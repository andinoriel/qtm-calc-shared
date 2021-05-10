#pragma once
#ifndef __QTM_DATA_HPP__
#define __QTM_DATA_HPP__

#include <qtm-calc/core.hpp>

namespace qtm {

/**
 * Queueing system analysis class
 *
 * ...
 *
 * Implements calculation of special characteristics of the queuing system
 */
class qtm_data final : private boost::noncopyable {
private:
  /**
   * Perform calculation the final states for a given instance of the queuing
   * system
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static void calc_fs_if_outdated(qtm &qtm);

public:
  qtm_data(void) = delete;
  ~qtm_data(void) = delete;

  /**
   * Perform calculation of the average queue size for a given instance
   * of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_avg_queue(qtm &qtm);
  /**
   * Perform calculation of the ETE for a given instance
   * of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_ete(qtm &qtm);
  /**
   * Perform calculation of the average time in queue for a given instance
   * of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_avg_time_queue(qtm &qtm);
  /**
   * Perform calculation of the percent of served requests for a given instance
   * of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_perc_served_req(qtm &qtm);
  /**
   * Perform calculation of the average count of served requests for a given
   * instance of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_avg_count_served_req(qtm &qtm);
  /**
   * Perform calculation of the average count of requests for a given instance
   * of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_avg_count_req(qtm &qtm);
  /**
   * Perform calculation of the average count of unserved requests for a given
   * instance of the queuing system and get the result
   *
   * @param[in] qtm Instance of qtm::qtm core class
   */
  static double calc_avg_count_unserved_req(qtm &qtm);
};

}; // namespace qtm

#endif // !__QTM_DATA_HPP__
