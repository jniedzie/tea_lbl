import os
import io
from PIL import Image
import fitz
from lbl_paths import base_path, skim

nEventsPerPlot = 200  #  NEE: 207, diphoton pT: 83, ZDC: 81: aco: 26
nPlots = 5
alpha = 0.2
overlayOnly = False

def open_pdf(path, page_number=0):
    
    doc = fitz.open(path)
    page = doc.load_page(page_number)  # Load the specified page
    pix = page.get_pixmap(matrix=fitz.Matrix(5.0, 5.0))  # Render page to an image
    
    img_buffer = io.BytesIO(pix.tobytes())
    img = Image.open(img_buffer)  # Open the image from the buffer
    
    doc.close()
    return img

def white_to_transparency(img):
    img = img.convert("RGBA")
    datas = img.getdata()

    newData = []
    for item in datas:
        # Change white (and nearly white, if desired) pixels to transparent
        if item[0] > 220 and item[1] > 220 and item[2] > 220:  # Adjust these values if needed
            newData.append((255, 255, 255, 0))  # Fully transparent
        else:
            newData.append(item)

    img.putdata(newData)
    return img

def main():
    
    outputPath = f"../plots/visualizations/{skim}/"
    
    files = []
    
    for i in range(nPlots):
        eventsOffset  = i * nEventsPerPlot
        outputFileName = f"{outputPath}/eventDisplay_{eventsOffset}.pdf"
        files.append(outputFileName)
        
        command = "./lbl_visualization_maker lbl_histogramer_config.py "
        command += f"{base_path}/collisionData/merged_{skim}.root "
        command += f"{outputFileName} {nEventsPerPlot} {eventsOffset}"
        
        if not overlayOnly:
            os.makedirs(os.path.dirname(outputFileName), exist_ok=True)
            os.system(command)
        
    images = []

    if len(files) == 1:
        image = open_pdf(files[0]).convert("RGBA")
        image.save(f"{outputPath}/composite_eventDisplay.png")
        return

    for file in files:
        image = open_pdf(file).convert("RGBA")
        image = white_to_transparency(image)
        image.putalpha(int(alpha*255))
        images.append(image)
    
    composite_image = Image.alpha_composite(images[0], images[1])
    
    for i in range(2, len(images)-1):
        composite_image = Image.alpha_composite(composite_image, images[i])
    
    composite_image = composite_image.convert("RGB")
    composite_image.save(f"{outputPath}/composite_eventDisplay.png")


if __name__ == '__main__':
    main()