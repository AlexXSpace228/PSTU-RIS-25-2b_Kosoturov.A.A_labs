#pragma once
using namespace System;

//Модель данных лабораторной работы
ref class LabItem
{
public:
    int Id; // - уникальный идентификатор
    String^ Title; // - название лабораторной
    String^ Status; // - текущий статус выполнения
    String^ Deadline; // - срок сдачи
    String^ Comment; // - комментарий пользователя
    String^ Task; // - список недостающих элементов
    String^ Path; // - путь к папке с файлами

    //Логические флаги
    //Булевые поля показывают, какие материалы требуются для лабораторной :
    bool NeedBD; // - нужна блок-схема
    bool NeedCode; // - нужен код
    bool NeedReport; // - нужен отчёт
    bool NeedIDEF; // - нужен IDEF0
};

//Перечисление LabColumns
//num LabColumns содержит индексы колонок ListView.
//Пример: selectedItem->SubItems[LabColumns::Task]

enum LabColumns
{
    Id = 0,
    Title = 1,
    Status = 2,
    Deadline = 3,
    Comment = 4,
    Task = 5,
    PAth = 6,
    BD = 7,
    Code = 8,
    Report = 9,
    IDEF0 = 10
};