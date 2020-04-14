#include "m_string.h"

void m_string::dispose() {
  if (this->p_str != nullptr) {
    delete[] this->p_str;
    this->p_str = nullptr;
  }
}

#pragma region class constructor
/* constructor */
m_string::m_string(const char *data_) {
  if (data_ != nullptr) {
    this->length = strlen(data_);
    this->p_str = new char[this->length + 1];
    strcpy(this->p_str, data_);
  }
}

/* copy constructor */
m_string::m_string(const m_string &str_l) {
  dispose();

  this->length = str_l.length;
  this->p_str = new char[str_l.length + 1];
  strcpy(this->p_str, str_l.p_str);
}

/* move constructor */
m_string::m_string(m_string &&str_r) {
  dispose();

  this->length = str_r.length;
  this->p_str = str_r.p_str;

  str_r.length = 0x0;
  str_r.p_str = nullptr;
}

/* destructor */
m_string::~m_string() {
  dispose();
}
#pragma endregion class constructor

#pragma region class assignment operator constructor
/* copy assignment operator */
m_string &m_string::operator=(const m_string &str_l) {
  dispose();

  this->length = str_l.length;
  this->p_str = new char[str_l.length + 1];
  strcpy(this->p_str, str_l.p_str);

  return *this;
}
/* move assignment operator */
m_string &&m_string::operator=(m_string &&str_r) {
  dispose();

  this->length = str_r.length;
  this->p_str = str_r.p_str;

  str_r.length = 0x0;
  str_r.p_str = nullptr;

  return move(*this);
}
#pragma endregion class assignment operator constructor

m_string &m_string::operator=(const char *data_) {
  if (data_ != nullptr) {
    int src_length = strlen(data_);

    if(src_length > this->length) {
      dispose();

      this->p_str = new char[src_length + 1];
      strcpy(this->p_str, data_);
    } else {
      memset(this->p_str, 0x0, this->length + 1);
      strcpy(this->p_str, data_);
    }

    this->length = src_length;
  }
  return *this;
}

char &m_string::operator[](int index) {
  return this->p_str[index];
}

m_string &m_string::operator+(const char *data_) {
  if (data_ == nullptr || this->p_str == nullptr) {
    return *this;
  }

  char *p_temp = this->p_str;

  this->p_str = new char[this->length + strlen(data_) + 1];
  strcpy(this->p_str, p_temp);
  strcat(this->p_str, data_);

  delete[] p_temp;
  return *this;
}