//----------------------------------------------------------------------------------------------------------------------
///
/// \file       statistics.cpp
/// \brief      Различные функции математической статистики
/// \date       08.02.21 - создан
/// \author     Соболев А.А.
/// \addtogroup spml
/// \{
///

#include <statistics.h>

namespace SPML /// Библиотека СБПМ
{
namespace Statistics /// Статистика
{
//----------------------------------------------------------------------------------------------------------------------
int Factorial( int x )
{
    assert( x >= 0 );
    int r = 1;
    if( x == 0 ) {
        return r;
    }
    r = x;
    while( --x > 1 ) {
        r *= x;
    }
    return r;
}
//----------------------------------------------------------------------------------------------------------------------
bool IsEven( int value )
{
    if( value % 2 == 0 ) {
        return true; // четное
    }
    return false; // не четное
}
//----------------------------------------------------------------------------------------------------------------------
float VolumeOfSphere( int n, float r )
{
    assert( n >= 0 );
    assert( r >= 0 );

    if( n == 0 ) {
        return 1.0f;
    }
    if( n == 1 ) {
        return ( 2.0f * r );
    }
    int k = 0; //    int k = n;
    float result = 0;

    if( ( n % 2 ) == 0 ) { // делится нацело
        k = static_cast<int>( floor( n / 2 ) );
        result = static_cast<float>( ( std::pow( Consts::PI_D, k ) / Factorial( k ) ) * std::pow( r, 2 * k ) );
        //result = ( ( std::pow( PI_F, k ) / Factorial( k ) ) * std::pow( r, 2 * k ) );
    } else {
        k = static_cast<int>( floor( ( n - 1 ) / 2 ) );
        result = static_cast<float>( ( ( 2 * Factorial( k ) * std::pow( ( 4 * Consts::PI_D ), k ) ) / Factorial( ( 2 * k ) + 1 ) )
        //result = ( ( ( 2 * Factorial( k ) * std::pow( ( 4 * PI_F ), k ) ) / Factorial( ( 2 * k ) + 1 ) )
            * std::pow( r, ( 2 * k ) + 1 ) );
    }
    return result;
}

double VolumeOfSphere( int n, double r )
{
    assert( n >= 0 );
    assert( r >= 0 );

    if( n == 0 ) {
        return 1.0;
    }
    if( n == 1 ) {
        return ( 2.0 * r );
    }
    int k = 0; //    int k = n;
    double result = 0;

    if( ( n % 2 ) == 0 ) { // делится нацело
        k = static_cast<int>( floor( n / 2 ) );
        result = ( ( std::pow( Consts::PI_D, k ) / Factorial( k ) ) * std::pow( r, 2 * k ) );
    } else {
        k = static_cast<int>( floor( ( n - 1 ) / 2 ) );
        result = ( ( ( 2 * Factorial( k ) * std::pow( ( 4 * Consts::PI_D ), k ) ) / Factorial( ( 2 * k ) + 1 ) )
            * std::pow( r, ( 2 * k ) + 1 ) );
    }
    return result;
}
//----------------------------------------------------------------------------------------------------------------------
float CalcRVSTR( float det, float strobe, float volume, int sizeY )
{
//    assert( !IsZero( det ) );       // определитель не должен быть равен нулю
    assert( !Compare::IsZero( volume ) );    // объем зоны не должен быть равен нулю

    double Vcoef = 0; // коэффициент объема эллипсоида рассеяния
    switch( sizeY ) { // в зависимости об размерности пространства измерений
        case 2:
        {
            Vcoef = Consts::PI_D;
            break;
        }
        case 3:
        {
            Vcoef = 4.0 * Consts::PI_D / 3.0;
            break;
        }
        case 4:
        {
            Vcoef = Consts::PI_D * Consts::PI_D / 2.0;
            break;
        }
        case 5:
        {
            Vcoef = 8.0 * Consts::PI_D * Consts::PI_D / 15.0;
            break;
        }
        case 6:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D / 6.0;
            break;
        }
        case 7:
        {
            Vcoef = 16.0 * Consts::PI_D * Consts::PI_D * Consts::PI_D / 105.0;
            break;
        }
        case 8:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 24.0;
            break;
        }
        case 9:
        {
            Vcoef = 32.0 * Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 945.0;
            break;
        }
        case 10:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 120.0;
            break;
        }
        default:
            assert( false );
    }
    return static_cast<float>( Vcoef * static_cast<double>( sqrt( std::abs( det ) ) ) * std::pow( strobe, sizeY ) ) / volume;
}

double CalcRVSTR( double det, double strobe, double volume, int sizeY )
{
//    assert( !IsZero( det, 1e-12 ) );    // определитель не должен быть равен нулю
    assert( !Compare::IsZero( volume ) );        // объем зоны не должен быть равен нулю

    double Vcoef = 0; // коэффициент объема эллипсоида рассеяния
    switch( sizeY ) { // в зависимости об размерности пространства измерений
        case 2:
        {
            Vcoef = Consts::PI_D;
            break;
        }
        case 3:
        {
            Vcoef = 4.0 * Consts::PI_D / 3.0;
            break;
        }
        case 4:
        {
            Vcoef = Consts::PI_D * Consts::PI_D / 2.0;
            break;
        }
        case 5:
        {
            Vcoef = 8.0 * Consts::PI_D * Consts::PI_D / 15.0;
            break;
        }
        case 6:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D / 6.0;
            break;
        }
        case 7:
        {
            Vcoef = 16.0 * Consts::PI_D * Consts::PI_D * Consts::PI_D / 105.0;
            break;
        }
        case 8:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 24.0;
            break;
        }
        case 9:
        {
            Vcoef = 32.0 * Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 945.0;
            break;
        }
        case 10:
        {
            Vcoef = Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D * Consts::PI_D / 120.0;
            break;
        }
        default:
            assert( false );
    }
    return ( ( Vcoef * ( sqrt( std::abs( det ) ) ) * std::pow( strobe, sizeY ) ) / volume );
}
//----------------------------------------------------------------------------------------------------------------------
float Freqs( float arg, int degree )
{
    assert( degree > 2 && degree < 10 );        // Ограничение на число степеней свободы
    float F = ChiSqPeizerPratt( arg, degree );  // Используем аппрокисимацию
    F = 1.0f - F;
    // Ограничим сверху и снизу
    if( F < 0.00001f ) {
        F = 0.00001f;
    }
    if( F > 0.99999f ) {
        F = 0.99999f;
    }
    return F;
}

double Freqs( double arg, int degree )
{
    assert( degree > 2 && degree < 10 );        // Ограничение на число степеней свободы
    double F = ChiSqPeizerPratt( arg, degree ); // Используем аппрокисимацию
    F = 1.0 - F;
    // Ограничим сверху и снизу
    if( F < 0.00001 ) {
        F = 0.00001;
    }
    if( F > 0.99999 ) {
        F = 0.99999;
    }
    return F;
}
//----------------------------------------------------------------------------------------------------------------------
float ChiSqPeizerPratt( float arg, int degree )
{
    assert( degree > 2 && degree < 10 );    // Ограничение на число степеней свободы
    float x = 0.0f;
    float t = arg * arg;
    if( Compare::AreEqual( t, degree - 1.0f ) ) { // if( t == v-1 )
        x = ( ( ( -1.0f / 3.0f ) + ( 0.08f / degree ) ) / sqrt( ( 2.0f * degree ) - 2.0f ) );
    } else {
        x = ( ( t - degree + ( 2.0f / 3.0f ) - ( 0.08f / degree ) ) / std::abs( t - ( degree - 1.0f ) ) ) *
            sqrt( ( degree - 1.0f ) * log( ( degree - 1.0f ) / t ) + t - ( degree - 1.0f ) );
    }
    float result = GaussCDF( x, 0, 1 );
    return result;
}

double ChiSqPeizerPratt( double arg, int degree )
{
    assert( degree > 2 && degree < 10 );    // Ограничение на число степеней свободы
    double x = 0.0;
    double t = arg * arg;
    if( Compare::AreEqual( t, degree - 1.0 ) ) { // if( t == v-1 )
        x = ( ( ( -1.0 / 3.0 ) + ( 0.08 / degree ) ) / sqrt( ( 2.0 * degree ) - 2.0 ) );
    } else {
        x = ( ( t - degree + ( 2.0 / 3.0 ) - ( 0.08 / degree ) ) / std::abs( t - ( degree - 1.0 ) ) ) *
            sqrt( ( degree - 1.0 ) * log( ( degree - 1.0 ) / t ) + t - ( degree - 1.0 ) );
    }
    double result = GaussCDF( x, 0, 1 );
    return result;
}
//----------------------------------------------------------------------------------------------------------------------
bool WaldCriterion( float pl, float &pc, float d, float &dcorr, float f, float ktsol, float &ad, float &ar, float &b )
{
    // Начальные значения порогов
    ad = -1e6;
    ar = 1e6;
    b = 1;

    int kt = static_cast<int>( ktsol );

    // Ограничим pl
    float tmp = 1e-6f;
    float pli = 0;
    pli = std::max( pl, tmp );
    pli = std::min( pl, 1.0f - tmp );

    float tmp0, tmp1, tmp2, tmp3;
    int ntakts;
    dcorr = d; // Начальное значение dcorr

//RepeatCalc:
    do {
        for( int i = 4; i < 19; i++ ) {
            pc = 0.05f * i;
            if( pc <= pli ) continue;
            for( int j = 1; j < kt; j++ ) {
                dcorr = d / static_cast<float>( 1.0 - std::pow( ( 1.0f - pc ), j ) );
                if( dcorr > 1.0f ) continue;

                tmp0 = log( f / dcorr );
                tmp1 = log( ( 1.0f - f ) / ( 1.0f - dcorr ) );
                tmp2 = log( pli / pc );
                tmp3 = log( ( 1.0f - pli ) / ( 1.0f - pc ) );

                ad = - tmp0 / ( tmp2 - tmp3 );
                ar = - tmp1 / ( tmp2 - tmp3 );
                b = tmp2 / ( tmp2 - tmp3 );

                ntakts = static_cast<int>( ( tmp0 * tmp1 ) / ( tmp2 * tmp3 ) + 0.5f );

                if( ( kt - ntakts ) >= j ) {
                    kt = kt - j;
                    goto LoopEnd; // нужно выйти из 2-ух вложенных циклов - goto оправдан
                }
            }
        }
LoopEnd:;
        if( ( std::abs( ad ) + std::abs( ar ) ) > 1e6f ) {
            dcorr *= 0.9f; // correct d
        } else {
            break; // break do-while loop - we 've finished
        }
    } while( dcorr >= 0.7f ); // 0.7 - нижний порог понижения d

    if( dcorr <= 0.7f ) {
        return false; // Fail!
    }
    return true; // OK
}

bool WaldCriterion( double pl, double &pc, double d, double &dcorr, double f, double ktsol, double &ad, double &ar, double &b )
{
    // Начальные значения порогов
    ad = -1e6;
    ar = 1e6;
    b = 1;

    int kt = static_cast<int>( ktsol );

    // Ограничим pl
    double tmp = 1e-6;
    double pli = 0.0;
    pli = std::max( pl, tmp );
    pli = std::min( pl, 1.0 - tmp );

    double tmp0, tmp1, tmp2, tmp3;
    int ntakts;
    dcorr = d; // Начальное значение dcorr

    do {
        for( int i = 4; i < 19; i++ ) {
            pc = 0.05 * i;
            if( pc <= pli ) continue;
            for( int j = 1; j < kt; j++ ) {
                dcorr = d / ( 1.0 - std::pow( ( 1.0 - pc ), j ) );
                if( dcorr > 1.0 ) continue;

                tmp0 = log( f / dcorr );
                tmp1 = log( ( 1.0 - f ) / ( 1.0 - dcorr ) );
                tmp2 = log( pli / pc );
                tmp3 = log( ( 1.0 - pli ) / ( 1.0 - pc ) );

                ad = - tmp0 / ( tmp2 - tmp3 );
                ar = - tmp1 / ( tmp2 - tmp3 );
                b = tmp2 / ( tmp2 - tmp3 );

                ntakts = static_cast<int>( ( tmp0 * tmp1 ) / ( tmp2 * tmp3 ) + 0.5 );

                if( ( kt - ntakts ) >= j ) {
                    kt = kt - j;
                    goto LoopEnd; // нужно выйти из 2-ух вложенных циклов - goto оправдан
                }
            }
        }
LoopEnd:;
        if( ( std::abs( ad ) + std::abs( ar ) ) > 1e6 ) {
            dcorr *= 0.9; // correct d
        } else {
            break; // break do-while loop - we 've finished
        }
    } while( dcorr >= 0.7 ); // 0.7 - нижний порог понижения d

    if( dcorr <= 0.7 ) {
        return false; // Fail!
    }
    return true; // OK
}

}
}
/// \}
