#pragma once
#ifndef __QTM_CORE_HPP__
#define __QTM_CORE_HPP__

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

#include <boost/core/noncopyable.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace qtm {

/**
 * Clamping the given value in given ranges
 *
 * @tparam type Type of the clamping value
 * @param[in] num Clamping value
 * @param[in] min_value Lower clamping limit
 * @param[in] max_value Upper clamping limit
 */
template <typename type> type clamp(type num, type min_value, type max_value) {
  return std::max(std::min(num, max_value), min_value);
}

/**
 * Core queuing class
 *
 * ...
 *
 * Implements basic construction and solving final states;
 * also available getters/setters of internal characteristics
 */
class qtm final : private boost::noncopyable {
private:
  std::uint64_t channel_count_, queue_size_;
  double la_, mu_, nu_;
  std::int64_t n_;
  boost::numeric::ublas::vector<double> final_states_;

  bool is_fs_outdated_;

  /**
   * Perform auxiliary matrix initialization for future calculation
   */
  static boost::numeric::ublas::matrix<double>
  matrix_init(std::uint64_t channel_count, std::uint64_t queue_size, double la,
              double mu, double nu, std::int64_t n);

public:
  /**
   * Class construnctor
   * Permorm construnction of the intance of the queuing system
   *
   * @param[in] channel_count Channel count of the queuing system
   * @param[in] queue_size Queue size of the queuing system
   * @param[in] la Input flow rate of the queuing system
   * @param[in] mu Output flow rate  of the queuing system
   * @param[in] nu Impatience rate of the queuing system
   * @param[in] n Load sources of the queuing system
   */
  explicit qtm(std::uint64_t channel_count, std::uint64_t queue_size, double la,
               double mu, double nu = 0, std::int64_t n = -1);
  ~qtm(void) = default;

  /**
   * Get the current value of the channel count of the queuing system
   */
  std::uint64_t channel_count(void) const;
  /**
   * Get the current value of the queue size of the queuing system
   */
  std::uint64_t queue_size(void) const;
  /**
   * Get the current value of the load sources of the queuing system
   */
  std::int64_t n(void) const;
  /**
   * Get the current value of the input flow rate of the queuing system
   */
  double la(void) const;
  /**
   * Get the current value of the output flow rate of the queuing system
   */
  double mu(void) const;
  /**
   * Get the current value of the impatience rate of the queuing system
   */
  double nu(void) const;

  /**
   * Set the value of the channel count of the queuing system
   *
   * @param[in] channel_count_ New value of channel count
   */
  void channel_count(std::uint64_t channel_count_);
  /**
   * Set the value of the queue size of the queuing system
   *
   * @param[in] channel_count_ New value of queue size
   */
  void queue_size(std::uint64_t queue_size_);
  /**
   * Set the value of the load sources of the queuing system
   *
   * @param[in] channel_count_ New value of load sources
   */
  void n(std::int64_t n_);
  /**
   * Get the current value of the input flow rate of the queuing system
   *
   * @param[in] channel_count_ New value of input flow rate
   */
  void la(double la_);
  /**
   * Set the value of the output flow rate of the queuing system
   *
   * @param[in] channel_count_ New value of output flow rate
   */
  void mu(double mu_);
  /**
   * Set the value of the impatience rate of the queuing system
   *
   * @param[in] channel_count_ New value of impatience rate
   */
  void nu(double nu_);

  /**
   * Get the current value of the final states of the queuing system
   *
   * @throws std::runtime_error Thrown if final states calculation was not
   * performed
   */
  std::vector<double> const final_states(void) const;
  /**
   * Get information that the final states hasn't been updated after changes
   * to the internal characteristics of the queuing system.
   */
  bool is_fs_outdated(void) const;
  /**
   * Perform calculation he final states of the queuing system.
   */
  std::vector<double> calc_final_states(void);
};

}; // namespace qtm

#endif // !__QTM_CORE_HPP__
