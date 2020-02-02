QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
	# Qt 5
	QT += widgets
}

TARGET = Chess
TEMPLATE = app

DESTDIR = build

OBJECTS_DIR = $$DESTDIR/objects
MOC_DIR = $$DESTDIR/moc
UI_DIR = $$DESTDIR/ui
RCC_DIR = $$DESTDIR/qrc

SOURCES = \
    source/board.cpp \
    source/border.cpp \
    source/main.cpp \
    source/tile.cpp \
    source/validation.cpp \
    source/game-engine.cpp

HEADERS = \
    headers/board.h \
    headers/border.h \
    headers/piece-color.h \
    headers/piece.h \
    headers/tile-color.h \
    headers/tile.h \
    headers/validation.h \
    headers/game-engine.h

RESOURCES += \
    Images/bishop_black.svg \
    Images/bishop_white.svg \
    Images/exp.png \
    Images/king_black.svg \
    Images/king_white.svg \
    Images/knight_black.svg \
    Images/knight_white.svg \
    Images/pawn_black.svg \
    Images/pawn_white.svg \
    Images/profile.png \
    Images/queen_black.svg \
    Images/queen_white.svg \
    Images/rook_black.svg \
    Images/rook_white.svg
