/////////////////
//
// Práctica de Compilación I (Curso 2010-2011)
//
//  FICHERO:        CRules.h
//  OBJETIVO:       Declaración de las reglas y sus atributos.
//  LICENCIA:       Mira el fichero LICENSE en el directorio raíz.
//  AUTORES:        El equipo del JAG.
//

#ifndef CRULES_H
#define	CRULES_H

#include "CRules_internal.h"

// Declaración de las reglas.
// DECLARE_RULE(nombre de la regla, atributos);
// FIRST_RULE_IS(símbolo inicial de la gramática);
DECLARE_RULE(programa);
DECLARE_RULE(declaraciones);
DECLARE_RULE(lista_de_ident, ids);
DECLARE_RULE(resto_lista_ident, ids);
DECLARE_RULE(tipo, tipo);
DECLARE_RULE(lista_de_enteros, ints);
DECLARE_RULE(resto_lista_enteros, ints);
DECLARE_RULE(decl_de_subprogs);
DECLARE_RULE(decl_de_procedimiento, nombre, args, classes );
DECLARE_RULE(decl_de_funcion, nombre, args, classes, tipoRetorno );
DECLARE_RULE(cabecera_procedimiento, nombre, args, classes );
DECLARE_RULE(cabecera_funcion, nombre, args, classes, tipoRetorno);
DECLARE_RULE(argumentos, args, classes );
DECLARE_RULE(lista_de_param, args, classes );
DECLARE_RULE(resto_lis_de_param, args, classes );
DECLARE_RULE(clase_param, clase);
DECLARE_RULE(clase_param_prima, clase);
DECLARE_RULE(lista_de_sentencias_prima);
DECLARE_RULE(lista_de_sentencias, salir_si, hinloop);
DECLARE_RULE(sentencia, salir_si, hinloop);
DECLARE_RULE(id_o_array, hident, nombre);
DECLARE_RULE(asignacion_o_llamada, hident );
DECLARE_RULE(acceso_a_array, hident, offset, tipo, htipo);
DECLARE_RULE(acceso_a_array_prima, exprs, tipos);
DECLARE_RULE(parametros_llamadas , hident, hrequireFunc, tipoRetorno );
DECLARE_RULE(expresion, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(disyuncion, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(disyuncion_prima, nombre, tipo, gtrue, gfalse, hnombre, htipo, hgtrue, hgfalse, literal, hliteral);
DECLARE_RULE(conjuncion, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(conjuncion_prima, nombre, tipo, gtrue, gfalse, hnombre, htipo, hgtrue, hgfalse, literal, hliteral);
DECLARE_RULE(relacional, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(relacional_prima, nombre, tipo, gtrue, gfalse, hnombre, htipo, hgtrue, hgfalse, literal, hliteral);
DECLARE_RULE(aritmetica, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(aritmetica_prima, nombre, tipo, gtrue, gfalse, hnombre, htipo, hgtrue, hgfalse, literal, hliteral);
DECLARE_RULE(termino, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(termino_prima, nombre, tipo, gtrue, gfalse, hnombre, htipo, hgtrue, hgfalse, literal, hliteral);
DECLARE_RULE(negacion, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(factor, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(factor_prima, nombre, tipo, gtrue, gfalse, literal);
DECLARE_RULE(array_o_llamada, hident, nombre, tipo);
DECLARE_RULE(acceso_a_array_opcional, nombre, tipo, hnombre, htipo);
DECLARE_RULE(lista_de_expr, exprs, tipos, literales);
DECLARE_RULE(resto_lista_expr, exprs, tipos, literales);
DECLARE_RULE(opl1, op);
DECLARE_RULE(opl2, op);
DECLARE_RULE(oprel, op);
DECLARE_RULE(booleano, value);
DECLARE_RULE(M, ref);

FIRST_RULE_IS(programa);

#endif	/* CRULES_H */

