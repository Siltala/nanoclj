(def true (equals? 1 1))
(def false (equals? 1 2))

(def force deref)
(def var-get second)

; Enable namespaces
; (def *slash-hook* (fn [sym ns] (var-get (resolve ns sym))))
(def *slash-hook* eval)

(def car first)
(def cdr rest)
(def cadr second)
(def cddr (fn [x] (rest (rest x))))
(def caadr (fn [x] (first (second x))))
(def cdadr (fn [x] (rest (second x))))

; First define the type for a cons cell
; (def cons (type '(1)))

; And create intern

; (macro (my-intern- form) (cons 'def (cons (caddr form) (cons (cadddr form) '()))))
; (def my-intern (fn [ns name val] (let [s name] (my-intern- ns s val))))

(def initialize-type-
  "Creates a symbol for the argument type"
  (fn [t doc] (intern root ((type 'first) t doc) t)))

; Create symbols for all types

(initialize-type- (type '()) "An empty list")
(initialize-type- (type true) "Constructs a boolean")
(initialize-type- (type (type 1)) "Constructs a type")
(initialize-type- (type '(1)) "Constructs a list")
(initialize-type- (type 1) "Casts argument to int")
(initialize-type- (type 2147483648) "Casts argument to a long (or int if it is sufficient)")
(initialize-type- (type 1.1) "Casts argument to a double")
(initialize-type- (type "") "Casts argument to a string")
(initialize-type- (type 'type) "Casts argument to a symbol")
(initialize-type- (type \a) "Casts argument to a character")
(initialize-type- (type *in*) "Constructs a reader")
(initialize-type- (type *out*) "Constructs a writer")
(initialize-type- (type :else) "Constructs a keyword")
(initialize-type- (type initialize-type-) "Constructs a function closure")
(initialize-type- (type type) "Constructs a procedure")
(initialize-type- (type *ns*) "Constructs a namespace")
(initialize-type- (type []) "Constructs a vector")
(initialize-type- (type (lazy-seq '())) "Constructs a lazy-seq")
(initialize-type- (type {}) "Constructs an array-map")
(initialize-type- (type #{}) "Constructs a sorted-set")
(initialize-type- (type Math/sin) "Constructs a foreign function")
(initialize-type- (type (divide 1 2)) "Constructs a ratio")
(initialize-type- (type (var divide)) "Constructs a Var")
; (initialize-type- (type (first {1 1})))

(def clojure.lang.BigInt (nanoclj.core.Type 26))
(def clojure.lang.MapEntry (nanoclj.core.Type 21))
(def nanoclj.core.CharArray (nanoclj.core.Type 27))
(def java.io.InputStream (nanoclj.core.Type 28))
(def java.io.OutputStream (nanoclj.core.Type 29))
(def clojure.lang.Delay (nanoclj.core.Type 31))
(def nanoclj.core.Image (nanoclj.core.Type 32))
(def nanoclj.core.Canvas (nanoclj.core.Type 33))

(def symbol clojure.lang.Symbol)
(def vector clojure.lang.PersistentVector)
(def cons clojure.lang.Cons)
(def boolean java.lang.Boolean)
(def char-array nanoclj.core.CharArray)
(def map-entry clojure.lang.MapEntry)
(def canvas nanoclj.core.Canvas)
(def image nanoclj.core.Image)

(def nil?
  "Returns true if the argument is nil"
  (fn [x] (identical? x nil)))

(def some?
  "Returns true if the argument is not nil"
  (fn [x] (not (identical? x nil))))

(def instance? (fn [t v] (identical? t (type v))))

(def list? (fn [x] (instance? clojure.lang.Cons x)))
(def zero? (fn [n] (equiv? n 0)))

(def is-any-of? (fn [x & args] (cond (empty? args) false
                                     (equals? x (first args)) true
                                     :else (apply* is-any-of? (cons x (rest args))))))

(def int?
  "Returns true if the argument is fixed-precision integer"
  (fn [x] (is-any-of? (type x) java.lang.Integer java.lang.Long)))

(def integer?
  "Returns true if the argument is integer"
  (fn [x] (is-any-of? (type x) java.lang.Integer java.lang.Long clojure.lang.BigInt)))

(def number?
  "Returns true if the argument is a number"
  (fn [x] (is-any-of? (type x)
                      java.lang.Integer java.lang.Long java.lang.Double
                      clojure.lang.BigInt clojure.lang.Ratio)))

(def string?
  "Returns true if argument is a string"
  (fn [x] (instance? java.lang.String x)))

(def symbol?
  "Returns true if argument is a symbol"
  (fn [x] (instance? clojure.lang.Symbol x)))

(def var?
  "Returns true if argument is a var"
  (fn [x] (instance? clolojure.lang.Var x)))

(def char?
  "Returns true if argument is a character"
  (fn [x] (instance? java.lang.Character x)))

(def procedure?
  "Returns true if the argument is a function"
  (fn [x] (is-any-of? (type x) nanoclj.core.Procedure nanoclj.core.Closure nanoclj.core.ForeignFunction)))

(def sorted?
  "Returns true if coll is a sorted collection"
  (fn [x] (instance? clojure.lang.PersistentTreeSet x)))

(def ifn?
  "Returns true if coll is invokeable"
  (fn [x] (is-any-of? (type x) nanoclj.core.Procedure nanoclj.core.Closure nanoclj.core.ForeignFunction clojure.lang.PersistentVector nanoclj.core.Macro clojure.lang.LazySeq nanoclj.core.Type clojure.lang.Keyword clojure.lang.PersistentArrayMap clojure.lang.PersistentTreeSet nanoclj.core.ForeignObject)))

(def defined? (fn [sym] (boolean (resolve sym))))
                        
(def list
  "Creates a list from the given args"
  (fn [& args] args))

(def spread
  (fn [args] (cond
               (nil? args) nil
               (nil? (next args)) (seq (first args))
               :else (cons (first args) (spread (next args))))))

(def list*
  "Creates a list with the initial arguments prepended to the last argument"
  (fn
    ([args] (seq args))
    ([a args] (cons a args))
    ([a b args] (cons a (cons b args)))
    ([a b c args] (cons a (cons b (cons c args))))
    ([a b c d & more] (cons a (cons b (cons c (cons d (spread more))))))))

(def apply
  "Calls the function f with the given args"
  (fn
    ([f args] (apply* f (seq args)))
    ([f a args] (apply* f (list* a args)))
    ([f a b args] (apply* f (list* a b args)))
    ([f a b c args] (apply* f (list* a b c args)))
    ([f a b c d & args] (apply* f (cons a (cons b (cons c (cons d (spread args)))))))))
             
;; The following quasiquote macro is due to Eric S. Tiedemann.
;;   Copyright 1988 by Eric S. Tiedemann; all rights reserved.
;;
;; Subsequently modified to handle vectors: D. Souflis

(macro
 quasiquote
 (fn [l]
   (let [mcons (fn [f l r]
                 (if (and (list? r)
                          (equals? (car r) 'quote)
                          (equals? (car (cdr r)) (cdr f))
                          (list? l)
                          (equals? (car l) 'quote)
                          (equals? (car (cdr l)) (car f)))
                   (if (or (procedure? f) (number? f) (string? f))
                     f
                     (list 'quote f))
                   (if (equals? l vector)
                     (apply l (eval r))
                     (list 'cons l r)
                     )))
         mappend (fn [f l r]
                   (if (or (empty? (cdr f))
                           (and (list? r)
                                (equals? (car r) 'quote)
                                (equals? (car (cdr r)) '())))
                     l
                     (list 'concat l r)))
         foo (fn [level form]
               (cond (not (list? form))
                     (if (or (procedure? form) (number? form) (string? form))
                       form
                       (list 'quote form))
               
                     (equals? 'quasiquote (car form))
                     (mcons form ''quasiquote (foo (+ level 1) (cdr form)))
                     :else (if (zero? level)
                             (cond (equals? (car form) 'unquote) (car (cdr form))
                                   (equals? (car form) 'unquote-splicing)
                                   (throw (str "Unquote-splicing wasn't in a list:" form))
                                   (and (list? (car form))
                                        (equals? (car (car form)) 'unquote-splicing))
                                   (mappend form (car (cdr (car form)))
                                            (foo level (cdr form)))
                                   :else (mcons form (foo level (car form))
                                                (foo level (cdr form))))
                             (cond (equals? (car form) 'unquote)
                                   (mcons form ''unquote (foo (- level 1)
                                                              (cdr form)))
                                   (equals? (car form) 'unquote-splicing)
                                   (mcons form ''unquote-splicing
                                          (foo (- level 1) (cdr form)))
                                   :else (mcons form (foo level (car form))
                                                (foo level (cdr form)))))))
         ]
     (foo 0 (car (cdr l))))))

; Implement type and predicate for macros now that we have a macro

(initialize-type- (type quasiquote) "Constructs a macro")

(def macro?
  "Returns true if the argument is a macro"
  (fn [x] (instance? nanoclj.core.Macro x)))

; DEFINE-MACRO Contributed by Andy Gaynor
(macro (def-macro dform)
  (if (symbol? (cadr dform))
    `(macro ,@(cdr dform))
    (let [form (gensym)]
      `(macro (,(caadr dform) ,form)
         (apply (fn ,(cdadr dform) ,@(cddr dform)) (cdr ,form))))))

;;;; Utility to ease macro creation
(def macroexpand (fn [form] ((eval (source (eval (car form)))) form)))

(def macro-expand-all (fn [form]
                        (if (macro? form)
                          (macro-expand-all (macroexpand form))
                          form)))

(def *compile-hook* macro-expand-all)

; (macro (defn form) `(intern *ns* ',(cadr form) (fn ,(caddr form) ,(cadddr form))))
; (macro my-def (fn [name expression] (cons 'intern (cons '*ns* (cons (symbol name) (cons 1 '()))))))

; (macro (defn-2 form) `(intern *ns* ',(cadr form) (fn ,(cddr form))))
; (def-macro (defn name params body) `(intern *ns* ',name (fn ,params ,body)))
; (def-macro (defn name params . body) `(intern *ns* ',name (fn ,params ,@body)))
(def-macro (defn name . args) (if (string? (car args))
                                `(def ,name ,(car args) (fn ,(cadr args) ,@(cddr args)))
                                `(def ,name (fn ,(car args) ,@(cdr args)))))
; (def-macro (my-cond . form) (if (empty? form) '() `(if ,(car form) ,(cadr form) nil)))
; (macro (my-cond form) (if (empty? (cdr form)) '() (cons 'if (cons (cadr form) (cons (caddr form) (my-cond (cdddr form)))))))


(def-macro (set! symbol value) `(set- ',symbol ,value))
             
(defn create-ns [sym] (eval (if (defined? sym) sym (intern *ns* sym (clojure.lang.Namespace *ns* (str sym))))))
(def-macro (ns name) `((create-ns ',name)))

(defn foldr [f x lst]
  (if (empty? lst)
    x
    (foldr f (f x (car lst)) (cdr lst))))

; variable arity (some subtle scope bug?)
(def-macro (or- . args)
  (if (empty? args)  ; zero arg or?
    nil
    (if (empty? (rest args)) ; one arg or?
      (first args)          
      `(let ((temp ,(car args)))
         (if temp
           temp
           (or- ,@(cdr args)))))))

;; (def-macro (cond- . args)
;;   (if (empty? args)  ; zero arg or?
;;     nil
;;     (if (empty? (rest args)) ; one arg or?
;;       nil
;;       `(if ,(car args)
;;          ,(cadr args)
;;          (cond- ,@(cddr args))))))

(def-macro (cond-- args)
  (if (empty? args)
    nil
    (if (empty? (rest args))
      nil
      (cons 'if (cons (car args) (cons (cadr args) (cons (cond-- (cddr args)) '())))))))

(def cond- (fn [& args] (cond-- args)))

(def-macro (case e . clauses)
  (if (empty? clauses) `(throw (str "No matching clause: " ,e))
      (if (empty? (rest clauses))
        (first clauses)
        `(if (equals? ,e ,(car clauses))
           ,(cadr clauses)
           (case ,e ,@(cddr clauses))))))

; Add multiarity versions of basic operators

(def reduce
  "Reduces a collection by applying f"
  (fn
    ([f coll] (if (empty? coll)
                (f)
                (if (empty? (rest coll))
                  (first coll)
                  (reduce f (f (first coll) (second coll)) (rest (rest coll))))))
    ([f val coll] (if (empty? coll)
                    val
                    (reduce f (f val (first coll)) (rest coll))))))

(defn max
  "Returns the maximum of the arguments"
  ([x] x)
  ([x y] (if (gt x y) x y))
  ([& args] (reduce #( if (gt %1 %2) %1 %2) args)))

(defn min
  "Returns the minimum of the arguments"
  ([x] x)
  ([x y] (if (lt x y) x y))
  ([& args] (reduce #( if (lt %1 %2) %1 %2) args)))

(defn +
  "Returns the sum of the arguments"
  ([x] x)
  ([x y] (add x y))
  ([x y & more] (reduce add (add x y) more)))

(defn *
  "Returns the product of the arguments"
  ([x] x)
  ([x y] (multiply x y))
  ([x y & more] (reduce multiply (multiply x y) more)))

(defn -
  "Subtracts the arguments"
  ([x] (minus 0 x))
  ([x y] (minus x y))
  ([x y & more] (reduce minus (minus x y) more)))

(defn /
  "Divides the arguments"
  ([x] (divide 1 x))
  ([x y] (divide x y))
  ([x y & more] (reduce divide (divide x y) more)))

(defn bit-or
  "Returns a bitwise or"
  ([x y] (bit-or- x y))
  ([x y & more] (reduce bit-or- (bit-or- x y) more)))

(defn bit-and
  "Returns a bitwise and"
  ([x y] (bit-and- x y))
  ([x y & more] (reduce bit-and- (bit-and- x y) more)))

(defn bit-xor
  "Returns a bitwise xor"
  ([x y] (bot-xor- x y))
  ([x y & more] (reduce bit-xor- (bit-xor- x y) args)))

(defn bit-not 
  "Returns a bitwise not"
  [x] (- 0 (inc x)))

(defn bit-test
  "Test a bit of x at index n"
  [x n] (if (equiv? (bit-and- x (bit-shift-left 1 n)) 0) false true))

(defn bit-set
  "Sets a bit of x at index n"
  [x n] (bit-or- x (bit-shift-left 1 n)))

(defn bit-clear
  "Clears a bit of x at index n"
  [x n] (bit-and- x (bit-not (bit-shift-left 1 n))))

(defn bit-flip
  "Flips a bit of x at index n"
  [x n] (bit-xor- x (bit-shift-left 1 n)))

(defn conj
  ([coll] coll)
  ([coll x] (-conj coll x))
  ([coll x & xs] (reduce -conj (-conj coll x) xs)))

(defn =
  "Returns true if the arguments are equal"
  ([x] true)
  ([x y] (equals? x y))
  ([x y & more] (if (equals? x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (equals? y (first more)))
                  false)))
  
(defn ==
  "Returns true if the arguments are numerically equal"
  ([x] true)
  ([x y] (equiv? x y))
  ([x y & more] (if (equiv? x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (equiv? y (first more)))
                  false)))

(defn <
  "Returns true if the arguments are in ascending order"
  ([x] true)
  ([x y] (lt x y))
  ([x y & more] (if (lt x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (lt y (first more)))
                  false)))

(defn >
  "Returns true if the arguments are in descending order"
  ([x] true)
  ([x y] (gt x y))
  ([x y & more] (if (gt x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (gt y (first more)))
                  false)))

(defn <=
  ([x] true)
  ([x y] (le x y))
  ([x y & more] (if (le x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (le y (first more)))
                  false)))

(defn >=
  ([x] true)
  ([x y] (ge x y))
  ([x y & more] (if (ge x y)
                  (if (next more)
                    (recur y (first more) (next more))
                    (ge y (first more)))
                  false)))

(defn not=
  "Returns true if the arguments are not equal"
  ([x] false)
  ([x y] (not (equals? x y)))
  ([x y & more] (not (apply equals? x y more))))

(def sorted-set
  "Creates a sorted set from the arguments"
  (fn [& keys] (reduce -conj #{} keys)))

(def array-map
  "Creates an array-map from the arguments"
  (fn [& keyvals]
    (let [f (fn [val seq]
              (if (empty? seq)
                val
                (recur (-conj val
                              (map-entry
                               (first seq)
                               (first (rest seq))))
                       (rest (rest seq))
                       )))]
      (f {} keyvals))))

(defn boolean?
  "Returns true if argument is a boolean"
  [x] (or (= x true) (= x false)))

(defn closure?
  "Returns true if argument is a closure. Note, a macro object is also a closure."
  [x] (or (instance? nanoclj.core.Closure x) (instance? nanoclj.core.Macro x)))

(macro (unless form)
     `(if (not ,(cadr form)) (do ,@(cddr form))))

(macro (when form)
       `(if ,(cadr form) (do ,@(cddr form))))

(macro (delay form) `(clojure.lang.Delay ',(cdr form)))
