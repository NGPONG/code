#include "person.hpp"

Person::Person(){};
Person::Person(std::string _name, int _id, int _score)
  : m_name(_name), m_id(_id) {
  memset(this->m_score, 0, sizeof(int) * 3);
};
Person::Person(const Person &per) {
  memcpy(this->m_score, per.m_score, sizeof(int) * 3);
  this->m_name = per.m_name;
  this->m_id = per.m_id;
};