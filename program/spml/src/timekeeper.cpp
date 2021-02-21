//----------------------------------------------------------------------------------------------------------------------
///
/// \file       timekeeper.cpp
/// \brief      Класс подсчета времени выполнения кода
/// \date       25.09.20 - создан
/// \author     Соболев А.А.
/// \addtogroup spml
/// \{
///

#include <timekeeper.h>

namespace SPML /// Библиотека СБПМ
{
namespace Statistics /// Статистика
{

CTimeKeeper::CTimeKeeper()
{
    time_curr = 0;
    time_summ = 0;
    time_perOp = 0;
    intervals_Number = 0;
}

void CTimeKeeper::StartTimer()
{
    start_curr = std::chrono::steady_clock::now();
}

void CTimeKeeper::EndTimer()
{
    // Статистика по текущей операции
    end_curr = std::chrono::steady_clock::now();
    duration_curr = end_curr - start_curr;
    time_curr = double( duration_curr.count() ) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

    // Суммарная статистика
    intervals_Number++;    
    time_summ += time_curr;
    time_perOp = time_summ / static_cast<double>( intervals_Number );
}

double CTimeKeeper::TimeSumm()
{
    return time_summ;
}

double CTimeKeeper::TimePerOp()
{
    return time_perOp;
}

int CTimeKeeper::IntervalsNumber()
{
    return intervals_Number;
}

}
}
/// \}
