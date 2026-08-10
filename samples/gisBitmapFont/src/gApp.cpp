#include "gApp.h"

#include "gCanvas.h"

gApp::gApp() = default;

gApp::gApp(int argc, char** argv) : gBaseApp(argc, argv) {
}

gApp::~gApp() = default;

void gApp::setup() {
	appmanager->setCurrentCanvas(new gCanvas(this));
}

void gApp::update() {
}
