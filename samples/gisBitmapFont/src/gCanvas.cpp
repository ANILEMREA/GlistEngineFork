#include "gCanvas.h"

#include <vector>

namespace {

const std::string characters =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789!?.,:;+-*/()[] ";

constexpr int cellwidth = 16;
constexpr int cellheight = 24;
constexpr int columncount = 16;

std::vector<gRect> createCharacterCoordinates() {
	std::vector<gRect> coordinates;
	coordinates.reserve(characters.size());
	for (std::size_t i = 0; i < characters.size(); ++i) {
		const int left = static_cast<int>(i % columncount) * cellwidth;
		const int top = static_cast<int>(i / columncount) * cellheight;
		coordinates.emplace_back(left, top, left + cellwidth, top + cellheight);
	}
	return coordinates;
}

} // namespace

gCanvas::gCanvas(gApp* root) : gBaseCanvas(root), root(root) {
}

gCanvas::~gCanvas() = default;

void gCanvas::setup() {
	enableAlphaBlending();

	if (!bitmapfont.loadFontImage("bitmapfont.png")) {
		gLoge("gisBitmapFont") << "Could not load bitmapfont.png";
	}
	bitmapfont.setCharacterList(characters);
	bitmapfont.setCharacterCoordinates(createCharacterCoordinates());
	if (!bitmapfont.isConfigured()) {
		gLoge("gisBitmapFont") << "Character list and bitmap coordinates do not match";
	} else {
		gLogi("gisBitmapFont") << "Bitmap font ready: "
				<< bitmapfont.getCharacterCount() << " characters";
	}
	bitmapfont.setLetterSpacing(1.0f);
}

void gCanvas::update() {
}

void gCanvas::draw() {
	clearColor(12, 16, 28);
	setColor(255, 255, 255);

	bitmapfont.setScale(1.0f);
	bitmapfont.drawText("Bitmap Font Sample", 48.0f, 64.0f);
	bitmapfont.drawText("ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz", 48.0f, 112.0f);

	bitmapfont.setScale(2.0f);
	bitmapfont.drawText("Scale 2x: 0123456789!", 48.0f, 192.0f);
}
