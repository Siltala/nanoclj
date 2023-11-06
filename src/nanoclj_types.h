#ifndef _NANOCLJ_TYPES_H_
#define _NANOCLJ_TYPES_H_

typedef union {
  uint64_t as_long;
  double as_double;
} nanoclj_val_t;

typedef enum {
  nanoclj_r8 = 1,
  nanoclj_ra8,
  nanoclj_rgb8,
  nanoclj_rgb565,
  nanoclj_rgba8,
  /* Cairo internal formats */
  nanoclj_bgr8_32,
  nanoclj_bgra8
} nanoclj_internal_format_t;

typedef struct {
  size_t refcnt;
  int32_t width, height, stride;
  nanoclj_internal_format_t format;
  unsigned char * data;
} nanoclj_image_t;

typedef struct {
  size_t refcnt;
  int32_t frames, channels, sample_rate;
  float * data;
} nanoclj_audio_t;

typedef struct {
  uint8_t red, green, blue, alpha;
} nanoclj_color_t;

typedef enum {
  nanoclj_colortype_none = 0,
  nanoclj_colortype_16,
  nanoclj_colortype_256,
  nanoclj_colortype_true
} nanoclj_colortype_t;

typedef enum {
  nanoclj_no_gfx = 0,
  nanoclj_sixel,
  nanoclj_kitty
} nanoclj_graphics_t;

typedef enum {
  nanoclj_mode_unknown = 0,
  nanoclj_mode_inline,
  nanoclj_mode_block
} nanoclj_display_mode_t;

typedef struct {
  nanoclj_color_t fg;
  nanoclj_color_t bg;
  nanoclj_graphics_t gfx;
  nanoclj_colortype_t color;
} nanoclj_termdata_t;

typedef struct {
  const uint8_t * ptr;
  uint32_t width, height, stride;
  nanoclj_internal_format_t format;
} imageview_t;

typedef struct {
  const char * ptr;
  size_t size;
} strview_t;

typedef struct {
  float x, y;
} nanoclj_vec2f;

typedef struct {
  nanoclj_vec2f pos, ppos;
  nanoclj_val_t data;
} nanoclj_node_t;

typedef struct {
  uint32_t source, target;
  nanoclj_val_t data;
} nanoclj_edge_t;

typedef struct {
  uint32_t num_nodes, num_edges, reserved_nodes, reserved_edges, refcnt;
  nanoclj_node_t * nodes;
  nanoclj_edge_t * edges;
} nanoclj_graph_array_t;

typedef struct {
  size_t num_rows, num_columns;
} nanoclj_table_t;

#endif
