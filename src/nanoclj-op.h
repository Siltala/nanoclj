_OP_DEF(0, 0, OP_NIL)
_OP_DEF("load-file", 0, OP_LOAD_FILE)
_OP_DEF(0, 0, OP_T0LVL)
_OP_DEF(0, 0, OP_T1LVL)
_OP_DEF("read", 0, OP_READ)
_OP_DEF("-read", 0, OP_READM)
_OP_DEF("gensym", "Generates an unique symbol", OP_GENSYM)
_OP_DEF(0, 0, OP_EVAL)
_OP_DEF(0, 0, OP_E0COLL)
_OP_DEF(0, 0, OP_E0ARGS)
_OP_DEF(0, 0, OP_E1ARGS)
_OP_DEF(0, 0, OP_APPLY)
_OP_DEF(0, 0, OP_DOMACRO)
_OP_DEF(0, 0, OP_LAMBDA)
_OP_DEF(0, 0, OP_LAMBDA1)
_OP_DEF(0, 0, OP_QUOTE)
_OP_DEF("intern", 0, OP_INTERN)
_OP_DEF(0, 0, OP_DEF0)
_OP_DEF(0, 0, OP_DEF1)
_OP_DEF(0, 0, OP_DO)
_OP_DEF(0, 0, OP_THREAD)
_OP_DEF(0, 0, OP_IF0)
_OP_DEF(0, 0, OP_IF1)
_OP_DEF("-set", "Sets var state", OP_SET)
_OP_DEF(0, 0, OP_LOOP)
_OP_DEF(0, 0, OP_DOTIMES0)
_OP_DEF(0, 0, OP_DOTIMES1)
_OP_DEF(0, 0, OP_DOTIMES2)
_OP_DEF(0, 0, OP_LET0)
_OP_DEF(0, 0, OP_LET1_VEC)
_OP_DEF(0, 0, OP_LET1)
_OP_DEF(0, 0, OP_LET2)
_OP_DEF(0, 0, OP_COND0)
_OP_DEF(0, 0, OP_COND1)
_OP_DEF(0, 0, OP_LAZYSEQ)
_OP_DEF(0, 0, OP_AND0)
_OP_DEF(0, 0, OP_AND1)
_OP_DEF(0, 0, OP_OR0)
_OP_DEF(0, 0, OP_OR1)
_OP_DEF(0, 0, OP_MACRO0)
_OP_DEF(0, 0, OP_MACRO1)
_OP_DEF(0, 0, OP_TRY)
_OP_DEF("eval", 0, OP_PEVAL)
_OP_DEF("apply*", 0, OP_PAPPLY)
_OP_DEF("rationalize", "Creates a Ratio out of a Double", OP_RATIONALIZE)
_OP_DEF("abs", "Returns the absolute value of the argument", OP_ABS)
_OP_DEF("inc", "Increases argument by one", OP_INC)
_OP_DEF("inc'", "Increases argument by one and auto-promotes", OP_INCP)
_OP_DEF("dec", "Decreases argument by one", OP_DEC)
_OP_DEF("dec'", "Descreases argument by one and auto-promotes", OP_DECP)
_OP_DEF("add", 0, OP_ADD)
_OP_DEF("add'", 0, OP_ADDP)
_OP_DEF("minus", 0, OP_SUB)
_OP_DEF("minus'", 0, OP_SUBP)
_OP_DEF("multiply", 0, OP_MUL)
_OP_DEF("multiply'", 0, OP_MULP)
_OP_DEF("divide", 0, OP_DIV)
_OP_DEF("quot", 0, OP_QUOT)
_OP_DEF("rem", 0, OP_REM)
_OP_DEF("peek", 0, OP_PEEK)
_OP_DEF("pop", 0, OP_POP)
_OP_DEF("first", 0, OP_FIRST)
_OP_DEF("second", 0, OP_SECOND)
_OP_DEF("key", 0, OP_KEY)
_OP_DEF("val", 0, OP_VAL)
_OP_DEF("rest", 0, OP_REST)
_OP_DEF("next", 0, OP_NEXT)
_OP_DEF("get", 0, OP_GET)
_OP_DEF("find", 0, OP_FIND)
_OP_DEF("contains?", 0, OP_CONTAINSP)
_OP_DEF("aget", 0, OP_AGET)
_OP_DEF("aset", 0, OP_ASET)
_OP_DEF("aclone", 0, OP_ACLONE)
_OP_DEF("-conj", 0, OP_CONJ)
_OP_DEF("-disj", 0, OP_DISJ)
_OP_DEF("count", 0, OP_COUNT)
_OP_DEF("-slice", 0, OP_SLICE)
_OP_DEF("not", 0, OP_NOT)
_OP_DEF("equiv?", 0, OP_EQUIV)
_OP_DEF("lt", 0, OP_LT)
_OP_DEF("gt", 0, OP_GT)
_OP_DEF("le", 0, OP_LE)
_OP_DEF("ge", 0, OP_GE)
_OP_DEF("equals?", 0, OP_EQ)
_OP_DEF("-bit-and", 0, OP_BIT_AND)
_OP_DEF("-bit-or", 0, OP_BIT_OR)
_OP_DEF("-bit-xor", 0, OP_BIT_XOR)
_OP_DEF("bit-shift-left", 0, OP_BIT_SHIFT_LEFT)
_OP_DEF("bit-shift-right", 0, OP_BIT_SHIFT_RIGHT)
_OP_DEF("unsigned-bit-shift-right", 0, OP_UNSIGNED_BIT_SHIFT_RIGHT)
_OP_DEF("type", 0, OP_TYPE)
_OP_DEF("class", 0, OP_CLASS)
_OP_DEF("-dot", 0, OP_DOT)
_OP_DEF("instance?", 0, OP_INSTANCEP)
_OP_DEF("identical?", 0, OP_IDENTICALP)
_OP_DEF("deref", "Returns the current state of Var or Delay, which it also forces if if not already forced.", OP_DEREF)
_OP_DEF(0, 0, OP_SAVE_FORCED)
_OP_DEF("-pr", 0, OP_PR)
_OP_DEF("-print", 0, OP_PRINT)
_OP_DEF("-str", 0, OP_STR)
_OP_DEF("-write", 0, OP_WRITEM)
_OP_DEF("format", 0, OP_FORMAT)
_OP_DEF("throw", 0, OP_THROW)
_OP_DEF("-close", 0, OP_CLOSEM)
_OP_DEF(0, 0, OP_RD_SEXPR)
_OP_DEF(0, 0, OP_RD_LIST)
_OP_DEF(0, 0, OP_RD_VEC_ELEMENT)
_OP_DEF(0, 0, OP_RD_SET_ELEMENT)
_OP_DEF(0, 0, OP_RD_MAP_KEY)
_OP_DEF(0, 0, OP_RD_MAP_VALUE)
_OP_DEF(0, 0, OP_RD_AMP)
_OP_DEF(0, 0, OP_RD_QUOTE)
_OP_DEF(0, 0, OP_RD_DEREF)
_OP_DEF(0, 0, OP_RD_VAR)
_OP_DEF(0, 0, OP_RD_QQUOTE)
_OP_DEF(0, 0, OP_RD_QQUOTEVEC)
_OP_DEF(0, 0, OP_RD_UNQUOTE)
_OP_DEF(0, 0, OP_RD_UQTSP)
_OP_DEF(0, 0, OP_RD_FN)
_OP_DEF(0, 0, OP_RD_DOT)
_OP_DEF(0, 0, OP_RD_IGNORE)
_OP_DEF(0, 0, OP_RD_META)
_OP_DEF(0, 0, OP_RD_META2)
_OP_DEF("seq", 0, OP_SEQ)
_OP_DEF("rseq", 0, OP_RSEQ)
_OP_DEF("empty?", 0, OP_EMPTYP)
_OP_DEF("hash", 0, OP_HASH)
_OP_DEF("compare", 0, OP_COMPARE)
_OP_DEF("sort", 0, OP_SORT)
_OP_DEF("sort-by", 0, OP_SORT_BY)
_OP_DEF("utf8map", 0, OP_UTF8MAP)
_OP_DEF("-toupper", 0, OP_TOUPPER)
_OP_DEF("-tolower", 0, OP_TOLOWER)
_OP_DEF("-totitle", 0, OP_TOTITLE)
_OP_DEF("-category", 0, OP_CATEGORY)
_OP_DEF("meta", "Returns the metadata of the argument", OP_META)
_OP_DEF("with-meta", 0, OP_WITH_META)
_OP_DEF("in-ns", 0, OP_IN_NS)
_OP_DEF("re-pattern", 0, OP_RE_PATTERN)
_OP_DEF("re-find", 0, OP_RE_FIND)
_OP_DEF("add-watch", 0, OP_ADD_WATCH)
_OP_DEF("-get-cell-flags", 0, OP_GET_CELL_FLAGS)
_OP_DEF("namespace", 0, OP_NAMESPACE)
_OP_DEF("name", 0, OP_NAME)
_OP_DEF("-is", 0, OP_IS)
_OP_DEF("require", 0, OP_REQUIRE)
_OP_DEF("find-ns", "Returns the namespace with the symbol x or nil", OP_FIND_NS)
_OP_DEF("find-keyword", 0, OP_FIND_KEYWORD)
_OP_DEF("vector-of", "Returns a homogenous vector of given type", OP_VECTOR_OF)

/* Canvas ops */
_OP_DEF("set-color", 0, OP_SET_COLOR)
_OP_DEF("set-bg-color", 0, OP_SET_BG_COLOR)
_OP_DEF("set-font-size", 0, OP_SET_FONT_SIZE)
_OP_DEF("set-line-width", 0, OP_SET_LINE_WIDTH)
_OP_DEF("move-to", 0, OP_MOVETO)
_OP_DEF("line-to", 0, OP_LINETO)
_OP_DEF("arc", 0, OP_ARC)
_OP_DEF("new-path", 0, OP_NEW_PATH)
_OP_DEF("close-path", 0, OP_CLOSE_PATH)
_OP_DEF("text-path", 0, OP_TEXT_PATH)
_OP_DEF("clip", 0, OP_CLIP)
_OP_DEF("reset-clip", 0, OP_RESET_CLIP)
_OP_DEF("stroke", 0, OP_STROKE)
_OP_DEF("stroke-preserve", 0, OP_STROKE_PRESERVE)
_OP_DEF("fill", 0, OP_FILL)
_OP_DEF("fill-preserve", 0, OP_FILL_PRESERVE)
_OP_DEF("get-text-extents", 0, OP_GET_TEXT_EXTENTS)
_OP_DEF("save", 0, OP_SAVE)
_OP_DEF("restore", 0, OP_RESTORE)
_OP_DEF("resize", 0, OP_RESIZE)
_OP_DEF("flush", 0, OP_FLUSH)
_OP_DEF("mode", 0, OP_MODE)
_OP_DEF("translate", 0, OP_TRANSLATE)
_OP_DEF("scale", 0, OP_SCALE)
_OP_DEF("rotate", 0, OP_ROTATE)
#undef _OP_DEF
