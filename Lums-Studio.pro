QT              += core gui widgets
SOURCES         = $$files(src/*.cpp)
HEADERS         = $$files(src/*.hpp)
FORMS           = $$files(ui/*.ui)
OBJECTS_DIR     = build/obj
UI_DIR          = build/ui
MOC_DIR         = build/moc
DESTDIR         = bin
