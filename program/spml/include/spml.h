//----------------------------------------------------------------------------------------------------------------------
///
/// \file       spml.h
/// \brief      SPML (Special Program Modules Library) - Cпециальная Библиотека Программных Модулей (СБПМ)
/// \details    Единый заголовочный файл библиотеки SPML (его подключение включает полностью всю библиотеку).
/// \date       14.07.20 - создан
/// \author     Соболев А.А.
/// \defgroup   spml Cпециальная Библиотека Программных Модулей (СБПМ)
/// \addtogroup spml
/// \{
///

#ifndef SPML_H
#define SPML_H

#include <string>

// SPML includes:
#include <compare.h>
#include <consts.h>
#include <convert.h>
#include <geodesy.h>
#include <lap.h>
#include <statistics.h>
#include <timekeeper.h>
#include <units.h>

using namespace std;

namespace SPML /// Библиотека СБПМ
{
//----------------------------------------------------------------------------------------------------------------------
///
/// \brief Возвращает строку, содержащую информацию о версии
/// \return Строка версии в формате DD-MM-YY-VV_COMMENTS, где DD - день, MM - месяц, YY - год, VV - версия, COMMENTS - комментарий(опционально)
///
std::string GetVersion();

}
#endif // SPML_H
/// \}
