#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/X.h>

int main() {
    
    XWarpPointer(XDefaultScreenOfDisplay());
}