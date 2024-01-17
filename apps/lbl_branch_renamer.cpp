#include "ConfigManager.hpp"
#include "Helpers.hpp"

using namespace std;

map<string, vector<float>*> vectors;

void SetupBranchesForMerging(TTree* tree, TTree* outputTree, map<string, vector<string>> &renameMap) {
  TObjArray* branches = tree->GetListOfBranches();
  for (int i = 0; i < branches->GetEntries(); ++i) {
    TBranch* branch = (TBranch*)branches->At(i);
    string branchName = branch->GetName();

    if(renameMap.find(branchName) == renameMap.end()) continue;

    string newBranchName = renameMap[branchName][0];

    if(renameMap[branchName][1] == "vector<float>"){
      vectors[branchName] = nullptr;
      tree->SetBranchAddress(branchName.c_str(), &vectors[branchName]);
      outputTree->Branch(renameMap[branchName][0].c_str(), &vectors[branchName]);
    }
    else{
      outputTree->Branch(newBranchName.c_str(), branch->GetAddress(), renameMap[branchName][1].c_str());
    }
  }
}

void MergeTrees(vector<TTree*> inputTrees, TTree* outputTree, map<string, vector<string>> &renameMap, int maxEntries = -1) {
  Long64_t nentries = maxEntries > 0 ? maxEntries : inputTrees[0]->GetEntries();

  for(auto tree : inputTrees) SetupBranchesForMerging(tree, outputTree, renameMap);
  
  for (Long64_t i = 0; i < nentries; ++i) {
    for(auto tree : inputTrees) tree->GetEntry(i);
    outputTree->Fill();
  }
}


void CheckArgs(int argc, char** argv) {
  if (argc != 2 && argc != 4) {
    fatal() << "Usage: " << argv[0] << " config_path" << endl;
    fatal() << "or" << endl;
    fatal() << argv[0] << " config_path input_path output_path" << endl;
    exit(1);
  }
}

int main(int argc, char** argv) {
  // Initialize ConfigManager with the path passed as an argument to the app
  ConfigManager::Initialize(argv[1]);

  auto& config = ConfigManager::GetInstance();

  string inputPath, outputPath;

  if (argc == 4) {
    inputPath = argv[2];
    outputPath = argv[3];
  } else {
    config.GetValue("inputFilePath", inputPath);
    config.GetValue("treeOutputFilePath", outputPath);
  }

  // Open the input files and get the trees
  auto inputFile = TFile::Open(inputPath.c_str());

  auto inputTree1 = (TTree*)inputFile->Get("ggHiNtuplizer/EventTree");  // Replace with your tree names
  auto inputTree2 = (TTree*)inputFile->Get("rechitanalyzerpp/zdcrechit");
  auto inputTree3 = (TTree*)inputFile->Get("l1object/L1UpgradeFlatTree");

  // Create the output file and tree
  auto outputFile = new TFile(outputPath.c_str(), "recreate");
  auto outputTree = new TTree("Events", "Events");

  // Define the branch renaming map
  map<string, vector<string>> renameMap;
  config.GetMap("branchesNames", renameMap);

  // Process each tree
  MergeTrees({inputTree1, inputTree2, inputTree3}, outputTree, renameMap, 100);

  // Write the output tree to the file
  outputTree->Write();
  outputFile->Close();

  return 0;
}
