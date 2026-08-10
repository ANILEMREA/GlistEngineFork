#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gApp.h"
#include "gBaseCanvas.h"
#include "gBitmapFont.h"

class gCanvas : public gBaseCanvas {
public:
	explicit gCanvas(gApp* root);
	~gCanvas();

	void setup() override;
	void update() override;
	void draw() override;

private:
	gApp* root;
	gBitmapFont bitmapfont;
};

#endif /* GCANVAS_H_ */
