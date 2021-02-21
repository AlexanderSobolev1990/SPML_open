//----------------------------------------------------------------------------------------------------------------------
///
/// \file       timekeeper.h
/// \brief      Класс подсчета времени выполнения кода
/// \date       25.09.20 - создан
/// \author     Соболев А.А.
/// \addtogroup spml
/// \{
///

#ifndef SPML_TIMEKEEPER_H
#define SPML_TIMEKEEPER_H

#include <chrono>

namespace SPML /// Библиотека СБПМ
{
namespace Statistics /// Статистика
{
//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Класс для замера времени выполнения кода
///
class CTimeKeeper
{
public:
    void StartTimer();      ///< Запуск измерения
    void EndTimer();        ///< Текущее измерение завершено
    double TimeSumm();      ///< Интервал (суммарный) в секундах
    double TimePerOp();     ///< Интервал на 1 операцию в секундах
    int IntervalsNumber();  ///< Число замеренных интервалов

    CTimeKeeper(); ///< Конструктор
private:
    std::chrono::steady_clock::duration duration_summ; ///< Интервал (суммарный)
    int intervals_Number; ///< Число интервалов вошедших в суммарный интервал
    double time_summ; ///< Интервал (суммарный) в секундах
    double time_perOp;   ///< Интервал на 1 операцию в секундах

    std::chrono::steady_clock::time_point start_curr; ///< Начало измерения (текущего)
    std::chrono::steady_clock::time_point end_curr;  ///< Конец измерения (текущего)
    std::chrono::steady_clock::duration duration_curr; ///< Интервал (текущий)
    double time_curr;    ///< Интервал (текущий) в секундах
};

}
}
#endif // SPML_TIMEKEEPER_H
/// \}
