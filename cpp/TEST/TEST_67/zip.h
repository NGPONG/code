#include <iterator>
#include <tuple>
#include <utility>

template <typename T>
using navit_iter_type = decltype(std::declval<T>().begin());

template <typename T>
using navit_val_type = decltype(*std::declval<T>().begin());

template<typename... T>
class zip_itr_base
  : std::iterator<std::forward_iterator_tag,
                  std::tuple<navit_val_type<T>...>> {
private:
  std::tuple<navit_iter_type<T>...> iters_;

  template<std::size_t... I>
  auto deref(std::index_sequence<I...>) const {
    return typename zip_itr_base::value_type{ *std::get<I>(iters_)... };
  }

  template<std::size_t... I>
  void increment(std::index_sequence<I...>) {
    ((void)++std::get<I>(iters_), ...);
  }

public:
  explicit zip_itr_base(decltype(iters_) iters)
    : iters_{ std::move(iters) } {}

  zip_itr_base &operator++() {
    increment(std::index_sequence_for<T...>{});
    return *this;
  }

  zip_itr_base operator++(int) {
    auto saved{ *this };
    increment(std::index_sequence_for<T...>{});
    return saved;
  }

  bool operator!=(const zip_itr_base &other) const {
    return iters_ != other.iters_;
  }

  auto operator*() const {
    return deref(std::index_sequence_for<T...>{});
  }
};

template<typename... T>
class zipper {
public:
  struct iterator : zip_itr_base<T...> {
    iterator(navit_iter_type<T>... iters) : zip_itr_base<T...>(std::make_tuple(iters...)) {}
  };

public:
  zipper(T &... seqs) : begin_{ seqs.begin()... }, end_{ seqs.end()... } {}

  iterator begin() const {
    return begin_;
  }
  iterator end() const {
    return end_;
  }

private:
  iterator begin_;
  iterator end_;
};

// Sequences must be the same length.
template<typename... T>
auto zip(T &&... seqs) {
  return zipper<T...>{ seqs... };
}
