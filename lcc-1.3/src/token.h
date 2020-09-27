/* $Id: token.h,v 1.1.1.1 2004/03/24 04:37:33 sjp Exp $ */
/*
xx(symbol,	value,	prec,	op,	optree,	kind,	string)
*/
yy(0,         0, 0,  0,    0,      0,      0)
xx(FLOAT,     1, 0,  0,    0,      CHAR,   "float")
xx(DOUBLE,    2, 0,  0,    0,      CHAR,   "double")
xx(CHAR,      3, 0,  0,    0,      CHAR,   "char")
xx(SHORT,     4, 0,  0,    0,      CHAR,   "short")
xx(INT,       5, 0,  0,    0,      CHAR,   "int")
xx(UNSIGNED,  6, 0,  0,    0,      CHAR,   "unsigned")
xx(POINTER,   7, 0,  0,    0,      0,      "pointer")
xx(VOID,      8, 0,  0,    0,      CHAR,   "void")
xx(STRUCT,    9, 0,  0,    0,      CHAR,   "struct")
xx(UNION,    10, 0,  0,    0,      CHAR,   "union")
xx(FUNCTION, 11, 0,  0,    0,      0,      "function")
xx(ARRAY,    12, 0,  0,    0,      0,      "array")
xx(ENUM,     13, 0,  0,    0,      CHAR,   "enum")
xx(LONG,     14, 0,  0,    0,      CHAR,   "long")
xx(CONST,    15, 0,  0,    0,      CHAR,   "const")
xx(VOLATILE, 16, 0,  0,    0,      CHAR,   "volatile")
yy(0,        17,     0,      0,    0,      0,      0)
yy(0,        18,     0,      0,    0,      0,      0)
yy(0,        19,     0,      0,    0,      0,      0)
yy(0,        20,     0,      0,    0,      0,      0)
yy(0,        21,     0,      0,    0,      0,      0)
yy(0,        22,     0,      0,    0,      0,      0)
yy(0,        23,     0,      0,    0,      0,      0)
yy(0,        24,     0,      0,    0,      0,      0)
yy(0,        25,     0,      0,    0,      0,      0)
yy(0,        26,     0,      0,    0,      0,      0)
yy(0,        27,     0,      0,    0,      0,      0)
yy(0,        28,     0,      0,    0,      0,      "long long")
yy(0,        29,     0,      0,    0,      0,      0)
yy(0,        30,     0,      0,    0,      0,      0)
yy(0,        31,     0,      0,    0,      0,      "const volatile")
xx(ID,       32,     0,      0,    0,      ID,     "identifier")
yy(0,        33,     0,      0,    0,      ID,     "!")
xx(FCON,     34,     0,      0,    0,      ID,     "floating constant")
xx(ICON,     35,     0,      0,    0,      ID,     "integer constant")
xx(SCON,     36,     0,      0,    0,      ID,     "string constant")
yy(0,        37,     13,     MOD,  bittree,'%',    "%")
yy(0,        38,     8,      BAND, bittree,ID,     "&")
xx(INCR,     39,     0,      ADD,  addtree,ID,     "++")
yy(0,        40,     0,      0,    0,      ID,     "(")
yy(0,        41,     0,      0,    0,      ')',    ")")
yy(0,        42, 13, MUL,  multree,ID,     "*")
yy(0,        43, 12, ADD,  addtree,ID,     "+")
yy(0,        44, 1,  0,    0,      ',',    ",")
yy(0,        45, 12, SUB,  subtree,ID,     "-")
yy(0,        46, 0,  0,    0,      '.',    ".")
yy(0,        47, 13, DIV,  multree,'/',    "/")
xx(DECR,     48, 0,  SUB,  subtree,ID,     "--")
xx(DEREF,    49, 0,  0,    0,      DEREF,  "->")
xx(ANDAND,   50, 5,  AND,  andtree,ANDAND, "&&")
xx(OROR,     51, 4,  OR,   andtree,OROR,   "||")
xx(LEQ,      52, 10, LE,   cmptree,LEQ,    "<=")
xx(EQL,         53,     9,      EQ,     eqtree, EQL,    "==")
xx(NEQ,         54,     9,      NE,     eqtree, NEQ,    "!=")
xx(GEQ,         55,     10,     GE,     cmptree,GEQ,    ">=")
xx(RSHIFT,      56,     11,     RSH,    shtree, RSHIFT, ">>")
xx(LSHIFT,      57,     11,     LSH,    shtree, LSHIFT, "<<")
yy(0,           58,     0,      0,      0,      ':',    ":")
yy(0,           59,     0,      0,      0,      IF,     ";")
yy(0,           60,     10,     LT,     cmptree,'<',    "<")
yy(0,           61,     2,      ASGN,   asgntree,'=',   "=")
yy(0,           62,     10,     GT,     cmptree,'>',    ">")
yy(0,           63,     0,      0,      0,      '?',    "?")
xx(ELLIPSIS,    64,     0,      0,      0,      ELLIPSIS,"...")
xx(SIZEOF,      65,     0,      0,      0,      ID,     "sizeof")
yy(0,           66,     0,      0,      0,      0,      0)
xx(AUTO,        67,     0,      0,      0,      STATIC, "auto")
xx(BREAK,       68,     0,      0,      0,      IF,     "break")
xx(CASE,        69,     0,      0,      0,      IF,     "case")
xx(CONTINUE,    70,     0,      0,      0,      IF,     "continue")
xx(DEFAULT,     71,     0,      0,      0,      IF,     "default")
xx(DO,          72,     0,      0,      0,      IF,     "do")
xx(ELSE,        73,     0,      0,      0,      IF,     "else")
xx(EXTERN,      74,     0,      0,      0,      STATIC, "extern")
xx(FOR,         75,     0,      0,      0,      IF,     "for")
xx(GOTO,        76,     0,      0,      0,      IF,     "goto")
xx(IF,          77,     0,      0,      0,      IF,     "if")
xx(REGISTER,    78,     0,      0,      0,      STATIC, "register")
xx(RETURN,      79,     0,      0,      0,      IF,     "return")
xx(SIGNED,      80,     0,      0,      0,      CHAR,   "signed")
xx(STATIC,      81,     0,      0,      0,      STATIC, "static")
xx(SWITCH,      82,     0,      0,      0,      IF,     "switch")
xx(TYPEDEF,     83,     0,      0,      0,      STATIC, "typedef")
xx(WHILE,       84,     0,      0,      0,      IF,     "while")
xx(TYPECODE,    85,     0,      0,      0,      ID,     "__typecode")
xx(FIRSTARG,    86,     0,      0,      0,      ID,     "__firstarg")
xx(ASM,         87,     0,      0,      0,      IF,     "__asm")
yy(0,           88,     0,      0,      0,      0,      0)
yy(0,           89,     0,      0,      0,      0,      0)
yy(0,           90,     0,      0,      0,      0,      0)
yy(0,           91,     0,      0,      0,      '[',    "[")
yy(0,           92,     0,      0,      0,      0,      0)
yy(0,           93,     0,      0,      0,      ']',    "]")
yy(0,           94,     7,      BXOR,   bittree,'^',    "^")
yy(0,           95,     0,      0,      0,      0,      0)
yy(0,           96,     0,      0,      0,      0,      0)
yy(0,           97,     0,      0,      0,      0,      0)
yy(0,           98,     0,      0,      0,      0,      0)
yy(0,           99,     0,      0,      0,      0,      0)
yy(0,           100,    0,      0,      0,      0,      0)
yy(0,           101,    0,      0,      0,      0,      0)
yy(0,           102,    0,      0,      0,      0,      0)
yy(0,           103,    0,      0,      0,      0,      0)
yy(0,           104,    0,      0,      0,      0,      0)
yy(0,           105,    0,      0,      0,      0,      0)
yy(0,           106,    0,      0,      0,      0,      0)
yy(0,           107,    0,      0,      0,      0,      0)
yy(0,           108,    0,      0,      0,      0,      0)
yy(0,           109,    0,      0,      0,      0,      0)
yy(0,           110,    0,      0,      0,      0,      0)
yy(0,           111,    0,      0,      0,      0,      0)
yy(0,           112,    0,      0,      0,      0,      0)
yy(0,           113,    0,      0,      0,      0,      0)
yy(0,           114,    0,      0,      0,      0,      0)
yy(0,           115,    0,      0,      0,      0,      0)
yy(0,           116,    0,      0,      0,      0,      0)
yy(0,           117,    0,      0,      0,      0,      0)
yy(0,           118,    0,      0,      0,      0,      0)
yy(0,           119,    0,      0,      0,      0,      0)
yy(0,           120,    0,      0,      0,      0,      0)
yy(0,           121,    0,      0,      0,      0,      0)
yy(0,           122,    0,      0,      0,      0,      0)
yy(0,           123,    0,      0,      0,      IF,     "{")
yy(0,           124,    6,      BOR,    bittree,'|',    "|")
yy(0,           125,    0,      0,      0,      '}',    "}")
yy(0,           126,    0,      BCOM,   0,      ID,     "~")
xx(EOI,         127,    0,      0,      0,      EOI,    "end of input")
#undef xx
#undef yy
