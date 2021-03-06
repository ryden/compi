/////////////////
//
// Práctica de Compilación I (Curso 2010-2011)
//
//  FICHERO:        CString.h
//  OBJETIVO:       Declaración de la clase de manejo de strings.
//  LICENCIA:       Mira el fichero LICENSE en el directorio raíz.
//  AUTORES:        El equipo del JAG.
//

#ifndef CSTRING_H
#define	CSTRING_H

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <string>
#include <vector>
#include "util.h"

class CString
{
private:
    std::string     m_str;
public:
    CString () {};
    CString ( const char* str ) : m_str ( str ) {}
    CString ( const std::string& str ) : m_str ( str ) {}
    CString ( const CString& Right ) : m_str ( Right.m_str ) {}
    CString ( bool bValue ) : m_str ( bValue ? "true" : "false" ) {}
    CString ( unsigned int uiValue ) { operator=(uiValue); }
    CString ( int iValue ) { operator=(iValue); }

    CString& operator= ( const CString& Right )
    {
        m_str = Right.m_str;
        return *this;
    }
    CString& operator= ( const char* str )
    {
        m_str.assign ( str );
        return *this;
    }
    CString& operator= ( const std::string& str )
    {
        m_str = str;
        return *this;
    }
    CString& operator= ( bool bValue )
    {
        m_str = bValue ? "true" : "false";
        return *this;
    }
    CString& operator= ( int iValue )
    {
        char temp [ 16 ];
        snprintf ( temp, NUMELEMS(temp), "%d", iValue );
        m_str.assign ( temp );
        return *this;
    }
    CString& operator= ( unsigned int uiValue )
    {
        char temp [ 16 ];
        snprintf ( temp, NUMELEMS(temp), "%u", uiValue );
        m_str.assign ( temp );
        return *this;
    }

    const char* operator* () const
    {
        return m_str.c_str ();
    }
    
    operator const char*() const
    {
        return m_str.c_str ();
    }

    const std::string& GetString () const { return m_str; }

    CString operator|| ( const CString& Right ) const
    {
        CString ret ( *this );
        ret.m_str.append ( Right.m_str );
        return ret;
    }

    CString operator|| ( const char* Right ) const
    {
        CString ret ( *this );
        ret.m_str.append ( Right );
        return ret;
    }

    CString operator|| ( int iRight ) const
    {
        return operator|| ( CString ( iRight ) );
    }

    bool operator== ( const char* Right ) const
    {
        return m_str == Right;
    }
    bool operator== ( const CString& Right ) const
    {
        return m_str == Right.m_str;
    }
    bool operator== ( unsigned int uiRight ) const
    {
        return operator== ( CString ( uiRight ) );
    }
    bool operator== ( int iRight ) const
    {
        return operator== ( CString ( iRight ) );
    }
    bool operator== ( bool bRight ) const
    {
        return operator== ( CString ( bRight ) );
    }
    bool operator!= ( const char* Right ) const
    {
        return !operator==(Right);
    }
    bool operator!= ( const CString& Right ) const
    {
        return !operator==(Right);
    }
    bool operator!= ( unsigned int uiRight ) const
    {
        return !operator==(uiRight);
    }
    bool operator!= ( int iRight ) const
    {
        return !operator==(iRight);
    }
    bool operator!= ( bool bRight ) const
    {
        return !operator==(bRight);
    }

    bool operator< ( const CString& Right ) const
    {
        return ( strcmp ( *this, Right ) < 0 );
    }
    bool operator<= ( const CString& Right ) const
    {
        return ( strcmp ( *this, Right ) <= 0 );
    }
    bool operator> ( const CString& Right ) const
    {
        return ( strcmp ( *this, Right ) > 0 );
    }
    bool operator>= ( const CString& Right ) const
    {
        return ( strcmp ( *this, Right ) >= 0 );
    }

    int operator+ ( int Right ) const
    {
        return intValue() + Right;
    }
    int operator- ( int Right ) const
    {
        return intValue() - Right;
    }
    int operator* ( int Right ) const
    {
        return intValue() * Right;
    }
    int operator/ ( int Right ) const
    {
        return intValue() / Right;
    }
    bool operator< ( int Right ) const
    {
        return intValue() > Right;
    }
    bool operator<= ( int Right ) const
    {
        return intValue() > Right;
    }
    bool operator> ( int Right ) const
    {
        return intValue() >= Right;
    }
    bool operator>= ( int Right ) const
    {
        return intValue() >= Right;
    }
    int intValue () const
    {
        return atoi(m_str.c_str());
    }

    char& operator[] ( int idx )
    {
        return m_str.operator[] ( idx );
    }
    const char& operator[] ( int idx ) const
    {
        return m_str.operator[] ( idx );
    }

    unsigned int Length () const
    {
        return m_str.length ();
    }

    void Resize ( unsigned int uiSize )
    {
        m_str.resize ( uiSize );
    }
    void Resize ( unsigned int uiSize, char c )
    {
        m_str.resize ( uiSize, c );
    }

    void Append ( const CString& Right )
    {
        m_str.append ( Right.m_str );
    }
    void Append ( const char* str )
    {
        m_str.append ( str );
    }

    void CollapseWhiteSpaces ()
    {
        unsigned int uiLength = Length ();
        char szTemp [ uiLength + 1 ];
        unsigned int copyPos = 0;

        for ( unsigned int i = 0; i < uiLength; ++i )
        {
            if ( m_str[i] != ' ' && m_str[i] != '\t' && m_str[i] != '\xA0' &&
                 m_str[i] != '\r' && m_str[i] != '\n' )
            {
                szTemp [ copyPos ] = m_str [ i ];
                ++copyPos;
            }
        }
        
        szTemp [ copyPos ] = '\0';
        m_str.assign ( szTemp );
    }

    std::vector<CString>& Split ( char cSeparator, std::vector<CString>& to ) const
    {
        size_t iPos = std::string::npos;
        size_t iLastPos = 0;
        
        while ( ( iPos = m_str.find ( cSeparator, iPos + 1 ) ) != std::string::npos )
        {
            to.push_back ( m_str.substr(iLastPos, iPos - iLastPos) );
            iLastPos = iPos + 1;
        }
        to.push_back ( m_str.substr( iLastPos, m_str.length() - iLastPos ) );

        return to;
    }
};

class Format : public CString
{
public:
    explicit Format ( const char* format, ... )
    {
        va_list vl;
        char temp [ 512 ];
        va_start ( vl, format );
        vsnprintf ( temp, NUMELEMS(temp), format, vl );
        va_end ( vl );

        *static_cast<CString *> ( this ) = temp;
    }
};

#endif	/* CSTRING_H */

