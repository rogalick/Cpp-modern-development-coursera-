﻿#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//Вам необходимо написать функцию PrintStats, получающую вектор людей, вычисляющую и выводящую медианный возраст для каждой из следующих групп людей:

//все люди;
//все женщины;
//все мужчины;
//все занятые женщины;
//все безработные женщины;
//все занятые мужчины;
//все безработные мужчины.
enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;
    Gender gender;
    bool is_employed;
};
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    auto las = partition(begin(persons), end(persons),
        [](const Person& person) {
            return person.gender == Gender::FEMALE;
        });
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), las) << endl;
    cout << "Median age for males = " << ComputeMedianAge(las, persons.end()) << endl;
    auto last = partition(begin(persons), las,
        [](const Person& person) {
            return person.is_employed;
        });
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), last) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(last, las) << endl;
    last = partition(las, persons.end(),
        [](const Person& person) {
            return person.is_employed;
        });
    cout << "Median age for employed males = " << ComputeMedianAge(las, last) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(last, persons.end()) << endl;
}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}