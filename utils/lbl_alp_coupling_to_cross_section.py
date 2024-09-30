import ROOT

def get_xsec(mass, coupling):
    slope = 0.498809
    interstect = {
        5.0: 1.3352627780449595e-05,
        6.0: 1.459208443729578e-05,
        9.0: 1.8432339658251058e-05,
        11.0: 2.051773548082086e-05,
        14.0: 2.4387325416686648e-05,
        16.0: 2.643930742885861e-05,
        22.0: 3.323868088097294e-05,
        30.0: 4.4114845375054456e-05,
        50.0: 7.817673899208805e-05,
        90.0: 0.00019612635077675486,
    }

    cross_section = ROOT.pow(10, (ROOT.log10(coupling) - ROOT.log10(interstect[mass]))/slope)
    scale = 1e-6

    return cross_section*scale

def main():

    mass = 30
    coupling = 0.25
    
    print(f"Coupling: {coupling} TeV^-1\t x-sec: {get_xsec(mass, coupling)} nb")

if __name__ == "__main__":
    main()
