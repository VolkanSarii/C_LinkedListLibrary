#define _CRT_SECURE_NO_WARNINGS
#include "my_utility.h"



/**
 * @brief random_name function returns a randomly selected name from a predefined list of names.
 *
 * @retval const char*, Pointer to the randomly selected name string.
 */
static const char* random_name(void)
{
    static const char* const pnames[] = {
    "Ahmet", "Mehmet", "Ali", "Veli", "Hasan", "Huseyin", "Ayse", "Fatma", "Emre", "Zeynep",
    "Omer", "Yusuf", "Mustafa", "Serkan", "Selim", "Esra", "Gizem", "Can", "Deniz", "Derya",
    "Emir", "Elif", "Burak", "Berk", "Sinem", "Gokhan", "Meltem", "Seda", "Bora", "Tugba",
    "Ferhat", "Pelin", "Sevda", "Sibel", "Ece", "Naz", "Nehir", "Bahar", "Cem", "Berat",
    "Sahin", "Ugur", "Dogan", "Tamer", "Betul", "Ilker", "Ipek", "Damla", "Furkan", "Beril",
    "Eren", "Yilmaz", "Gul", "Ayla", "Baran", "Koray", "Nihat", "Enes", "Selda", "Okan",
    "Hayri", "Cihan", "Feyza", "Merve", "Sami", "Eda", "Ekin", "Ozan", "Cemil", "Tuna",
    "Hande", "Hakan", "Ilhan", "Sevil", "Ersin", "Pinar", "Onur", "Suat", "Beliz", "Ismet",
    "Safiye", "Bahar", "Yigit", "Lale", "Ediz", "Taner", "Saniye", "Bilal", "Dilek", "Murat",
    "Altan", "Alev", "Baris", "Arzu", "Zeki", "Buket", "Necla", "Beste", "Canan", "Merve",
    "Yesim", "Nejat", "Serdar", "Burcu", "Nazan", "Sinan", "Riza", "Leyla", "Buse", "Rahmi",
    "Cagla", "Safa", "Teoman", "Sevilay", "Halil", "Esin", "Ayhan", "Sultan", "Ahsen", "Davut",
    "Hulya", "Yalcin", "Tarik", "Emel", "Eylem", "Sezer", "Sermin", "Gokce", "Serpil", "Arif",
    "Yakup", "Erdem", "Melih", "Tan", "Akin", "Semih", "Nazli", "Ceren", "Seher", "Zuhal",
    "Evren", "Deniz", "Ayla", "Ekin", "Cihan", "Sevgi", "Mehve", "Ilayda", "Nazim", "Guney",
    "Onder", "Binnaz", "Berkay", "Ferda", "Sadi", "Zekiye", "Ulas", "Rana", "Zerrin", "Mete",
    "Talha", "Mithat", "Enis", "Umit", "Adem", "Yasar", "Nuran", "Ayca", "Tugce", "Suat",
    "Emrah", "Atilla", "Derya", "Oguz", "Sinem", "Sevda", "Ufuk", "Yesim", "Nevin", "Ceyda",
    "Elvan", "Aytac", "Yasemin", "Nail", "Funda", "Kutay", "Ozge", "Ozan", "Aykut", "Nevzat",
    "Gulcin", "Orhan", "Bilge", "Turgay", "Senay", "Filiz", "Gonca", "Berrin", "Selim", "Sami",
    "Ender", "Asil", "Burhan", "Halime", "Sezgin", "Gulsum", "Nida", "Gizem", "Selen", "Yelda"
    };

    return get_random_element(pnames);

}

static uint8_t random_ages(void)
{
    static const uint8_t ages[] = {
    25, 34, 19, 42, 50, 28, 31, 24, 29, 37,
    21, 46, 30, 27, 33, 22, 35, 40, 23, 26,
    38, 32, 18, 45, 20, 36, 39, 41, 49, 47,
    44, 48, 43, 52, 55, 53, 58, 60, 54, 57,
    62, 61, 59, 63, 64, 65, 66, 67, 68, 70,
    71, 72, 74, 73, 75, 76, 78, 77, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 56,
    51, 50, 48, 47, 45, 43, 42, 41, 40, 39,
    38, 37, 36, 35, 34, 33, 32, 31, 30, 29,
    28, 27, 26, 25, 24, 23, 22, 21, 20, 19,
    18, 17, 16, 15, 14, 13, 12, 11, 10, 9,
    8, 7, 6, 5, 4, 3, 2, 1, 18, 22,
    26, 28, 30, 32, 35, 37, 40, 43, 45, 48,
    50, 55, 57, 60, 62, 65, 67, 70, 73, 75,
    78, 80, 83, 85, 88, 90, 93, 95, 98, 25,
    30, 35, 40, 45, 50, 55, 60, 65, 70, 75,
    80, 85, 90, 95, 18, 20, 22, 24, 26, 28,
    30, 32, 34, 36, 38, 40, 42, 44, 46, 48,
    50, 52, 54, 56, 58, 60, 62, 64, 66, 68,
    70, 72, 74, 76, 78, 80, 82, 84, 86, 88,
    90, 92, 94, 96, 98, 100, 19, 23, 27, 31,
    35, 39, 43, 47, 51, 55, 59, 63, 67, 71
    };

    return get_random_element(ages);
}

Employee* set_employee_random(Employee* p)
{
    strcpy(p->m_name, random_name());
    p->ages = random_ages();
    

    return p;
}


