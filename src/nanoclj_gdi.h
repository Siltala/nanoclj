#ifndef _NANOCLJ_GDI_H_
#define _NANOCLJ_GDI_H_

#include <wingdi.h>
#include <winuser.h>

#include "nanoclj_utils.h"

#define NANOCLJ_HAS_CANVAS 1

static void finalize_canvas(nanoclj_t * sc, void * canvas) {
  if (canvas) {
    HDC hdc = (HDC)canvas;
    DeleteDC(hdc);
  }
}

static inline nanoclj_val_t mk_canvas(nanoclj_t * sc, int width, int height) {
  HDC hdc = CreateCompatibleDC(NULL);
  HBITMAP bitmap = CreateBitmap(width, height, 3, 24, NULL);
  SelectObject(hdc, bitmap);
  
  struct cell * x = get_cell_x(sc, sc->EMPTY, sc->EMPTY);
  _typeflag(x) = T_CANVAS | T_GC_ATOM;
  _canvas_unchecked(x) = (void*)hdc;
  _metadata_unchecked(x) = mk_nil();
  
  return mk_pointer(x);  
}

static inline nanoclj_val_t canvas_create_image(nanoclj_t * sc, void * canvas) {
  HDC hdc = (HDC)canvas;
  return mk_nil();
}

static inline void canvas_set_color(void * canvas, double r0, double g0, double b0) {
  HDC hdc = (HDC)canvas;
  int r = clamp((int)(r0 / 255), 0, 255), g = clamp((int)(g0 / 255), 0, 255), b = clamp((int)(b0 / 255), 0, 255);
  SetDCBrushColor(hdc, RGB(r, g, b));
  SetDCPenColor(hdc, RGB(r, g, b));
}

static inline void canvas_move_to(void * canvas, double x, double y) {
  MoveToEx((HDC)canvas, (int)x, (int)y, NULL);  
}

static inline void canvas_line_to(void * canvas, double x, double y) {
  LineTo((HDC)canvas, (int)x, (int)y);  
}

static inline void canvas_stroke(void * canvas) {

}

static inline void canvas_fill(void * canvas) {

}

static inline void canvas_close_path(void * canvas) {

}

static inline void canvas_save(void * canvas) {

}

static inline void canvas_restore(void * canvas) {

}

static inline void canvas_show_text(void * canvas, const char * text, size_t len) {
  HDC hdc = (HDC)canvas;

#if 0
  DrawText(hdc,
	   [in, out] LPCTSTR lpchText,
	   [in]      int     cchText,
	   [in, out] LPRECT  lprc,
	   [in]      UINT    format
	   );
#endif
}

#endif