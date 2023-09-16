_OP_DEF(0, OP_NIL)
_OP_DEF("load", OP_LOAD)
_OP_DEF(0, OP_T0LVL)
_OP_DEF(0, OP_T1LVL)
_OP_DEF("read", OP_READ)
_OP_DEF(".read", OP_READM)
_OP_DEF("gensym", OP_GENSYM)
_OP_DEF(0, OP_EVAL)
#if USE_TRACING
_OP_DEF(0, OP_REAL_EVAL)
#endif
_OP_DEF(0, OP_E0VEC)
_OP_DEF(0, OP_E0ARGS)
_OP_DEF(0, OP_E1ARGS)
_OP_DEF(0, OP_APPLY)
#if USE_TRACING
_OP_DEF(0, OP_REAL_APPLY)
_OP_DEF("tracing", OP_TRACING)
#endif
_OP_DEF(0, OP_DOMACRO)
_OP_DEF(0, OP_LAMBDA)
_OP_DEF(0, OP_LAMBDA1)
_OP_DEF(0, OP_QUOTE)
_OP_DEF(0, OP_VAR)
_OP_DEF("resolve", OP_RESOLVE)
_OP_DEF("intern", OP_INTERN)
_OP_DEF(0, OP_DEF0)
_OP_DEF(0, OP_DEF1)
_OP_DEF(0, OP_DO)
_OP_DEF(0, OP_IF0)
_OP_DEF(0, OP_IF1)
_OP_DEF("set-", OP_SET)
_OP_DEF(0, OP_LOOP)
_OP_DEF(0, OP_LET0)
_OP_DEF(0, OP_LET1_VEC)
_OP_DEF(0, OP_LET1)
_OP_DEF(0, OP_LET2)
_OP_DEF(0, OP_COND0)
_OP_DEF(0, OP_COND1)
_OP_DEF(0, OP_LAZYSEQ)
_OP_DEF(0, OP_AND0)
_OP_DEF(0, OP_AND1)
_OP_DEF(0, OP_OR0)
_OP_DEF(0, OP_OR1)
_OP_DEF(0, OP_MACRO0)
_OP_DEF(0, OP_MACRO1)
_OP_DEF(0, OP_TRY)
_OP_DEF("eval", OP_PEVAL)
_OP_DEF("apply*", OP_PAPPLY)
_OP_DEF("rationalize", OP_RATIONALIZE)
_OP_DEF("inc", OP_INC)
_OP_DEF("dec", OP_DEC)
_OP_DEF("add", OP_ADD)
_OP_DEF("minus", OP_SUB)
_OP_DEF("multiply", OP_MUL)
_OP_DEF("divide", OP_DIV)
_OP_DEF("rem", OP_REM)
_OP_DEF("first", OP_FIRST)
_OP_DEF("second", OP_SECOND)
_OP_DEF("rest", OP_REST)
_OP_DEF("next", OP_NEXT)
_OP_DEF("get", OP_GET)
_OP_DEF("find", OP_FIND)
_OP_DEF("contains?", OP_CONTAINSP)
_OP_DEF("-conj", OP_CONJ)
_OP_DEF("subvec", OP_SUBVEC)
_OP_DEF("not", OP_NOT)
_OP_DEF("equiv?", OP_EQUIV)
_OP_DEF("lt", OP_LT)
_OP_DEF("gt", OP_GT)
_OP_DEF("le", OP_LE)
_OP_DEF("ge", OP_GE)
_OP_DEF("equals?", OP_EQ)
_OP_DEF("bit-and-", OP_BIT_AND)
_OP_DEF("bit-or-", OP_BIT_OR)
_OP_DEF("bit-xor-", OP_BIT_XOR)
_OP_DEF("bit-shift-left", OP_BIT_SHIFT_LEFT)
_OP_DEF("bit-shift-right", OP_BIT_SHIFT_RIGHT)
_OP_DEF("type", OP_TYPE)
_OP_DEF("class", OP_CLASS)
_OP_DEF("instance?", OP_INSTANCEP)
_OP_DEF("identical?", OP_IDENTICALP)
_OP_DEF("deref", OP_DEREF)
_OP_DEF(0, OP_SAVE_FORCED)
_OP_DEF("pr-", OP_PR)
_OP_DEF("print-", OP_PRINT)
_OP_DEF("format", OP_FORMAT)
_OP_DEF("throw", OP_ERR0)
_OP_DEF("close", OP_CLOSE)
_OP_DEF(0, OP_RDSEXPR)
_OP_DEF(0, OP_RDLIST)
_OP_DEF(0, OP_RDVEC_ELEMENT)
_OP_DEF(0, OP_RDMAP_ELEMENT)
_OP_DEF(0, OP_RDDOT)
_OP_DEF(0, OP_RDQUOTE)
_OP_DEF(0, OP_RDDEREF)
_OP_DEF(0, OP_RDVAR)
_OP_DEF(0, OP_RDQQUOTE)
_OP_DEF(0, OP_RDQQUOTEVEC)
_OP_DEF(0, OP_RDUNQUOTE)
_OP_DEF(0, OP_RDUQTSP)
_OP_DEF(0, OP_RDFN)
_OP_DEF(0, OP_RDSET)
_OP_DEF(0, OP_RDMAP)
_OP_DEF("seq", OP_SEQ)
_OP_DEF("rseq", OP_RSEQ)
_OP_DEF("seq?", OP_SEQP)
_OP_DEF("empty?", OP_EMPTYP)
_OP_DEF("hash", OP_HASH)
_OP_DEF("compare", OP_COMPARE)
_OP_DEF("sort", OP_SORT)
_OP_DEF("utf8map", OP_UTF8MAP)
_OP_DEF("meta", OP_META)
_OP_DEF("in-ns", OP_IN_NS)
_OP_DEF("re-pattern", OP_RE_PATTERN)
_OP_DEF("add-watch", OP_ADD_WATCH)
_OP_DEF("realized?", OP_REALIZEDP)
_OP_DEF("name", OP_NAME)

/* Canvas ops */
_OP_DEF("set-color", OP_SET_COLOR)
_OP_DEF("set-font-size", OP_SET_FONT_SIZE)
_OP_DEF("set-line-width", OP_SET_LINE_WIDTH)
_OP_DEF("move-to", OP_MOVETO)
_OP_DEF("line-to", OP_LINETO)
_OP_DEF("arc", OP_ARC)
_OP_DEF("close-path", OP_CLOSE_PATH)
_OP_DEF("stroke", OP_STROKE)
_OP_DEF("fill", OP_FILL)
_OP_DEF("get-text-extents", OP_GET_TEXT_EXTENTS)
_OP_DEF("save", OP_SAVE)
_OP_DEF("restore", OP_RESTORE)
_OP_DEF("resize", OP_RESIZE)
_OP_DEF("flush", OP_FLUSH)

#undef _OP_DEF
