/////////////////
//
// Práctica de Compilación I (Curso 2010-2011)
//
//  FICHERO:        CTokenizer.h
//  OBJETIVO:       Declaración del autómata léxico.
//  LICENCIA:       Mira el fichero LICENSE en el directorio raíz.
//  AUTORES:        El equipo del JAG.
//

#ifndef CTOKENIZER_H
#define	CTOKENIZER_H

#include "CBufferedReader.h"
#include "CClassifier.h"
#include <cstring>

class CTokenizer
{
public:
    enum ETokenType
    {
        INTEGER = 0,
        REAL,
        IDENTIFIER,
        RESERVED,
        OPERATOR,
        COMMENT,
        SPACE,
        NEWLINE,
        SEPARATOR,

        UNKNOWN,

        // Para uso interno del traductor.
        EMPTY,
        END_OF_FILE,
        
        MAX_TOKEN_TYPE
    };

    enum
    {
        NUMSTATES = 19,
        BUFFER_SIZE = 1024
    };

    struct SToken
    {
        SToken ( ETokenType type = UNKNOWN, const char* szValue = "" )
        : eType ( type )
        , uiLine ( 0 )
        , uiCol ( 0 )
        , uiState ( 0 )
        {
            uiValueLength = strlen ( szValue );
            if ( uiValueLength > 0 )
                strncpy ( value, szValue, uiValueLength );
            value [ uiValueLength ] = '\0';
        }
        
        ETokenType      eType;
        char            value [ 1024 ];
        unsigned int    uiValueLength;
        unsigned int    uiLine;
        unsigned int    uiCol;
        unsigned int    uiState;
    };

private:
    typedef void (CTokenizer::*fn_stateTrigger) ( unsigned char );
    static const int                ms_iTransitions [ CTokenizer::NUMSTATES ] [ CClassifier::GROUP_MAX ];
    static const ETokenType         ms_eFinalStates [ NUMSTATES ];
    static fn_stateTrigger          ms_fnTriggers [ NUMSTATES ];
    static const char*              ms_szErrors [ NUMSTATES ];
    static const char*              ms_szReserved [ ];

public:
                    CTokenizer      ( std::istream& isInput );
    virtual         ~CTokenizer     ();

    bool            NextToken       ( SToken* pToken = 0, bool bIgnoreWhiteSpaces = true );
private:
    bool            ReadToken       ( SToken* pToken = 0 );
public:
    const char*     NameThisToken   ( ETokenType eType ) const;
    bool            IsReserved      ( const char* szTokenValue ) const;
    const char*     GetErrorForToken( const SToken& token ) const { return ms_szErrors [ token.uiState ]; }

private:
    void            CheckMultilineComment   ( unsigned char c );

private:
    CBufferedReader < BUFFER_SIZE > m_buffer;


    unsigned int    m_uiState;
    std::istream&   m_isInput;
};

#endif	/* CTOKENIZER_H */

