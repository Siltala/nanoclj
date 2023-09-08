#ifndef _NANOCLJ_CAIRO_H_
#define _NANOCLJ_CAIRO_H_

#include <cairo/cairo.h>

#define NANOCLJ_HAS_CANVAS 1

static void finalize_canvas(nanoclj_t * sc, void * canvas) {
  if (canvas) cairo_destroy((cairo_t *)canvas);
}

static inline nanoclj_val_t mk_canvas(nanoclj_t * sc, int width, int height) {
  cairo_surface_t * surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t * cr = cairo_create(surface);
  cairo_surface_destroy(surface);
  
  nanoclj_cell_t * x = get_cell_x(sc, NULL, NULL, NULL);
  x->type = T_CANVAS;
  x->flags = T_GC_ATOM;
  _canvas_unchecked(x) = cr;

  cairo_set_source_rgba(cr, 1, 1, 1, 1);
  cairo_rectangle(cr, 0, 0, width, height);
  cairo_fill(cr);
  cairo_set_source_rgba(cr, 0, 0, 0, 1);

  cairo_font_options_t * options = cairo_font_options_create();
  cairo_font_options_set_antialias(options,
#if 1
				   CAIRO_ANTIALIAS_SUBPIXEL
#else
				   CAIRO_ANTIALIAS_GRAY
#endif
				   );
  cairo_font_options_set_hint_style(options, CAIRO_HINT_STYLE_FULL);
  cairo_font_options_set_hint_metrics(options, CAIRO_HINT_METRICS_ON);
  cairo_set_font_options(cr, options);
  cairo_font_options_destroy(options);

  return mk_pointer(x);  
}

static inline nanoclj_val_t canvas_create_image(nanoclj_t * sc, void * canvas) {
  cairo_t * cr = (cairo_t *)canvas;
  cairo_surface_t * surface = cairo_get_target(cr);

  cairo_surface_flush(surface);
  
  unsigned char * data = cairo_image_surface_get_data(surface);
  int width = cairo_image_surface_get_width(surface);
  int height = cairo_image_surface_get_height(surface);
  
  return mk_image(sc, width, height, 4, data);
}

static inline void canvas_flush(void * canvas) {
  cairo_surface_flush(cairo_get_target((cairo_t *)canvas));
}

static inline void canvas_set_color(void * canvas, double r, double g, double b) {
  cairo_set_source_rgb((cairo_t *)canvas, r, g, b);
}

static inline void canvas_set_font_size(void * canvas, double size) {
  cairo_set_font_size((cairo_t *)canvas, size);
}

static inline void canvas_set_line_width(void * canvas, double w) {
  cairo_set_line_width((cairo_t *)canvas, w);
}

static inline void canvas_move_to(void * canvas, double x, double y) {
  cairo_move_to((cairo_t *)canvas, x, y);
}

static inline void canvas_line_to(void * canvas, double x, double y) {
  cairo_line_to((cairo_t *)canvas, x, y);
}

static inline void canvas_arc(void * canvas, double xc, double yc, double radius, double angle1, double angle2) {
  cairo_arc((cairo_t *)canvas, xc, yc, radius, angle1, angle2);
}

static inline void canvas_close_path(void * canvas) {
  cairo_close_path((cairo_t *)canvas);
}

static inline void canvas_stroke(void * canvas) {
  cairo_stroke((cairo_t *)canvas);
}

static inline void canvas_fill(void * canvas) {
  cairo_fill((cairo_t *)canvas);
}

static inline void canvas_save(void * canvas) {
  cairo_save((cairo_t *)canvas);
}

static inline void canvas_restore(void * canvas) {
  cairo_restore((cairo_t *)canvas);
}

static inline void canvas_show_text(nanoclj_t * sc, void * canvas, strview_t text) {
  char * tmp = alloc_cstr(sc, text);
  cairo_show_text((cairo_t *)canvas, tmp);
  sc->free(tmp);
}

static inline void canvas_get_text_extents(nanoclj_t * sc, void * canvas, strview_t text, double * width, double * height) {
  char * tmp = alloc_cstr(sc, text);
  cairo_text_extents_t extents;
  cairo_text_extents((cairo_t *)canvas, tmp, &extents);
  *width = extents.width;
  *height = extents.height;
  /* double x_bearing;
     double y_bearing;
     double x_advance;
     double y_advance; */
  sc->free(tmp);
}

#endif
