# Bitmap Font Sample

This sample demonstrates how to load an image-based font with `gBitmapFont`,
map a UTF-8 character list to bitmap rectangles, and render text with
`drawText()`.

The bundled atlas uses 16x24 pixel cells in a 16-column grid. Its character
order is defined in `src/gCanvas.cpp`. The atlas was generated from the
FreeSans font already distributed with the GlistEngine samples.
