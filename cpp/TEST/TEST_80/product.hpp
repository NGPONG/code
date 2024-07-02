#include <tuple>

template<typename... Ts>
class product_iterator;

template<typename... Ts>
class product;

template<typename T>
class product<T> {
  public:
    explicit product(const T &x) : m_x(x) {
    }

    product_iterator<T> begin() const;
    product_iterator<T> end() const;

  protected:
    const T &m_x;
};

template<typename T, typename... Ts>
class product<T, Ts...> {
  public:
    product(const T &x, const Ts&... xs) : m_x(x), m_xs(product<Ts...>(xs...)) {
    }

    product_iterator<T, Ts...> begin() const;
    product_iterator<T, Ts...> end() const;

  protected:
    const T &m_x;
    product<Ts...> m_xs;
};

template<typename T>
class product_iterator<T> {
    friend class product<T>;

  public:
    std::tuple<typename T::value_type> operator*() const {
        return std::make_tuple(*m_it);
    }

    const product_iterator<T> &operator++() {
        m_it++;
        return *this;
    }

    bool operator==(const product_iterator &other) const {
        return m_it == other.m_it;
    }

    bool operator!=(const product_iterator &other) const {
        return !(*this == other);
    }

  protected:
    typedef typename T::const_iterator t_iterator;

    product_iterator(t_iterator it, t_iterator end) : m_it(it), m_end(end) {}

    t_iterator m_it;
    t_iterator m_end;
};

template<typename T, typename... Ts>
class product_iterator<T, Ts...> {
    friend class product<T, Ts...>;

  public:
    decltype(auto) operator*() const {
      return std::tuple_cat(std::make_tuple(*m_x), *m_xs);
    }

    const product_iterator<T, Ts...> &operator++() {
        if (++m_xs == m_xs_end && ++m_x != m_x_end) {
            m_xs = m_xs_begin;
        }

        return *this;
    }

    bool operator==(const product_iterator &other) const {
        return m_x == other.m_x && m_xs == other.m_xs;
    }

    bool operator!=(const product_iterator &other) const {
        return !(*this == other);
    }

  protected:
    typedef typename T::const_iterator t_iterator;
    typedef product_iterator<Ts...> ts_iterator;

    product_iterator(t_iterator x, t_iterator x_end, ts_iterator xs,
                     ts_iterator xs_begin, ts_iterator xs_end)
        : m_x(x), m_x_end(x_end), m_xs(xs), m_xs_begin(xs_begin), m_xs_end(xs_end) {}

    t_iterator m_x;
    t_iterator m_x_end;
    ts_iterator m_xs;
    ts_iterator m_xs_begin;
    ts_iterator m_xs_end;
};

template<typename T>
product_iterator<T> product<T>::begin() const {
    return product_iterator<T>(m_x.begin(), m_x.end());
}

template<typename T>
product_iterator<T> product<T>::end() const {
    return product_iterator<T>(m_x.end(), m_x.end());
}

template<typename T, typename... Ts>
product_iterator<T, Ts...> product<T, Ts...>::begin() const {
    return product_iterator<T, Ts...>(m_x.begin(), m_x.end(), m_xs.begin(),
                                      m_xs.begin(), m_xs.end());
}

template<typename T, typename... Ts>
product_iterator<T, Ts...> product<T, Ts...>::end() const {
    return product_iterator<T, Ts...>(m_x.end(), m_x.end(), m_xs.end(), m_xs.begin(),
                                      m_xs.end());
}

template<typename... Ts>
product<Ts...> cartesian_product(Ts&... xs) {
    return product<Ts...>(xs...);
}

template<typename... Ts>
product<Ts...> cartesian_product(Ts&&... xs) {
    return product<Ts...>(xs...);
}

