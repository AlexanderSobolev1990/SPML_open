//----------------------------------------------------------------------------------------------------------------------
///
/// \file       statistics.h
/// \brief      Различные функции математической статистики
/// \date       08.02.21 - создан
/// \author     Соболев А.А.
/// \addtogroup spml
/// \{
///

#ifndef SPML_STATISTICS_H
#define SPML_STATISTICS_H

#include <cmath>
#include <cassert>
#include <algorithm>

// SPML includes:
#include <compare.h>

namespace SPML /// Библиотека СБПМ
{
namespace Statistics /// Статистика
{
//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Вычисление факториала (прямым способом умножения)
/// \param x - аргумент
/// \return Факториал аргумента x
///
int Factorial( int x );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Проверка на четность
/// \param value - проверяемое число
/// \return true - если число четное, false - если нечетное
///
bool IsEven( int value );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Вычисление объема n-мерной сферы радиуса r
/// \details
/// \param n - количество измерений пространства
/// \param r - радиус сферы
/// \return Объем n-мерной сферы радиуса r
///
float VolumeOfSphere( int n, float r );

///
/// \brief Вычисление объема n-мерной сферы радиуса r
/// \details
/// \param n - количество измерений пространства
/// \param r - радиус сферы
/// \return Объем n-мерной сферы радиуса r
///
double VolumeOfSphere( int n, double r );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Вычисление относительного объема строба (RVSTR - relative volume of strobe)
/// \param[in] det    - определитель матрицы S
/// \param[in] strobe - строб
/// \param[in] volume - объем, относительно которого вычисляется RVSTR (может быть объем зоны обзора, эл-та разрешения и т.д.)
/// \param[in] sizeY  - размерность вектора измерений
/// \return Относительный объем строба
///
float CalcRVSTR( float det, float strobe, float volume, int sizeY );

///
/// \brief Вычисление относительного объема строба (RVSTR - relative volume of strobe)
/// \param[in] det    - определитель матрицы S
/// \param[in] strobe - строб
/// \param[in] volume - объем, относительно которого вычисляется RVSTR (может быть объем зоны обзора, эл-та разрешения и т.д.)
/// \param[in] sizeY  - размерность вектора измерений
/// \return Относительный объем строба
///
double CalcRVSTR( double det, double strobe, double volume, int sizeY );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Функция распределения F(x^2) = (1 - CDF(x^2)), где CDF - cumulative distribution function.
/// \param[in] arg    - аргумент
/// \param[in] degree - степень свободы
/// \return Возвращает значение F(x^2) = 1 - ChiSquared(x^2, degree)
///
float Freqs( float arg, int degree );

///
/// \brief Функция распределения F(x^2) = (1 - CDF(x^2)), где CDF - cumulative distribution function.
/// \param[in] arg    - аргумент
/// \param[in] degree - степень свободы
/// \return Возвращает значение F(x^2) = 1 - ChiSquared(x^2, degree)
///
double Freqs( double arg, int degree );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Гауссовская (нормальная) функция распределения
/// \param[in] x - аргумент
/// \param[in] m - математическое ожидание
/// \param[in] s - среднеквадратическое отклонение, СКО
/// \return Значение функции распределения при заданных аргументах
///
inline float GaussCDF( float x, float m, float s )
{
    return ( 1.0f + erf( ( x - m ) / ( s * sqrt( 2.0f ) ) ) ) / 2.0f;
}

///
/// \brief Гауссовская (нормальная) функция распределения
/// \param[in] x - аргумент
/// \param[in] m - математическое ожидание
/// \param[in] s - среднеквадратическое отклонение, СКО
/// \return Значение функции распределения при заданных аргументах
///
inline double GaussCDF( double x, double m, double s )
{
    return ( 1.0 + erf( ( x - m ) / ( s * sqrt( 2.0 ) ) ) ) / 2.0;
}

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Аппроксимация Пейзера-Пратта для закона распределения хи-квадрат
/// \details По материалам "Аппроксимация центрального распределения хи-квадрат для оперативного расчета
///          вероятности ложной тревоги энергетического обнаражителя" Лесников, Наумович, Частиков, Дубовцев,
///          Вятский государственный университет, Киров, МЭС-2016
/// \param[in] arg    - аргумент
/// \param[in] degree - степень свободы
/// \return Возвращает F(x^2) = ChiSquared(x^2, degree)
///
float ChiSqPeizerPratt( float arg, int degree );

///
/// \brief Аппроксимация Пейзера-Пратта для закона распределения хи-квадрат
/// \details По материалам "Аппроксимация центрального распределения хи-квадрат для оперативного расчета
///          вероятности ложной тревоги энергетического обнаражителя" Лесников, Наумович, Частиков, Дубовцев,
///          Вятский государственный университет, Киров, МЭС-2016
/// \param[in] arg    - аргумент
/// \param[in] degree - степень свободы
/// \return Возвращает F(x^2) = ChiSquared(x^2, degree)
///
double ChiSqPeizerPratt( double arg, int degree );

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Экспоненциальное скользящее среднее (Exponential Moving Average)
/// \param[in] ema_prev - предыдущее значение EMA (в момент времени t-1)
/// \param[in] alpha    - сглаживающая переменная (0..1)
/// \param[in] x        - сглаживаемое значение (в текущий момент времени t)
/// \return Экспоненциально усредненное значение аргумента x
///
inline float EMA( float ema_prev, float alpha, float x )
{
    assert( alpha > 0.0f && alpha < 1.0f );
    return ( ( alpha * x ) + ( ( 1.0f - alpha ) * ema_prev ) );
}

///
/// \brief Экспоненциальное скользящее среднее (Exponential Moving Average)
/// \param[in] ema_prev - предыдущее значение EMA (в момент времени t-1)
/// \param[in] alpha    - сглаживающая переменная (0..1)
/// \param[in] x        - сглаживаемое значение (в текущий момент времени t)
/// \return Экспоненциально усредненное значение аргумента x
///
inline double EMA( double ema_prev, double alpha, double x )
{
    assert( alpha > 0.0 && alpha < 1.0 );
    return ( ( alpha * x ) + ( ( 1.0 - alpha ) * ema_prev ) );
}

///
/// \brief Экспоненциальное скользящее среднее (Exponential Moving Average)
/// \param[in] ema_prev - предыдущее значение EMA (в момент времени t-1)
/// \param[in] alpha    - сглаживающая переменная (0..1)
/// \param[in] x        - сглаживаемое значение (в текущий момент времени t)
/// \return Экспоненциально усредненное значение аргумента x
///
inline float EMA( float ema_prev, float alpha, int x )
{
    assert( alpha > 0.0f && alpha < 1.0f );
    return ( ( alpha * static_cast<float>( x ) ) + ( ( 1.0f - alpha ) * ema_prev ) );
}

///
/// \brief Экспоненциальное скользящее среднее (Exponential Moving Average)
/// \param[in] ema_prev - предыдущее значение EMA (в момент времени t-1)
/// \param[in] alpha    - сглаживающая переменная (0..1)
/// \param[in] x        - сглаживаемое значение (в текущий момент времени t)
/// \return Экспоненциально усредненное значение аргумента x
///
inline double EMA( double ema_prev, double alpha, int x )
{
    assert( alpha > 0.0 && alpha < 1.0 );
    return ( ( alpha * x ) + ( ( 1.0 - alpha ) * ema_prev ) );
}

//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Критерий Вальда
/// \details Модифицирован по источнику: Абчук В.А. Справочник по исследованию операций/ Под общ. ред. Ф.А.Матвейчука - М.:Воентиздат, 1979, стр 29
/// \details и первоисточнику: Вальд А. Последовательный анализ под ред. А.Ф. Лапко М.:Гос. изд-во физ.-мат. лит. 1960, стр 125
/// \param[in]  pl    - вероятность ложной отметки в стробе
/// \param[out] pc    - вероятность целевой отметки в стробе
/// \param[in]  d     - заданная вероятность правильного обнаружения
/// \param[out] dcorr - скорректированная вероятность правильного обнаружения
/// \param[in]  f     - поток ложных тревог, приведенный к такту измерений
/// \param[in]  ktsol - число тактов на принятие решений
/// \param[out] ad    - коэффициент порога обнаружения
/// \param[out] ar    - коэффициент порога сброса
/// \param[out] b     - коэффициент b
/// \return true в случае успешных вычислений, false в случае неудачи
///
bool WaldCriterion( float pl, float &pc, float d, float &dcorr, float f, float ktsol, float &ad, float &ar, float &b );

///
/// \brief Критерий Вальда
/// \details Модифицирован по источнику: Абчук В.А. Справочник по исследованию операций/ Под общ. ред. Ф.А.Матвейчука - М.:Воентиздат, 1979, стр 29
/// \details и первоисточнику: Вальд А. Последовательный анализ под ред. А.Ф. Лапко М.:Гос. изд-во физ.-мат. лит. 1960, стр 125
/// \param[in]  pl    - вероятность ложной отметки в стробе
/// \param[out] pc    - вероятность целевой отметки в стробе
/// \param[in]  d     - заданная вероятность правильного обнаружения
/// \param[out] dcorr - скорректированная вероятность правильного обнаружения
/// \param[in]  f     - поток ложных тревог, приведенный к такту измерений
/// \param[in]  ktsol - число тактов на принятие решений
/// \param[out] ad    - коэффициент порога обнаружения
/// \param[out] ar    - коэффициент порога сброса
/// \param[out] b     - коэффициент b
/// \return 0 в случае успешных вычислений, 1 в случае неудачи
///
bool WaldCriterion( double pl, double &pc, double d, double &dcorr, double f, double ktsol, double &ad, double &ar, double &b );



}
}
#endif // SPML_STATISTICS_H
/// \}
