#include <qtm-calc/data.hpp>

namespace qtm {

void qtm_data::calc_fs_if_outdated(qtm &qtm) {
  if (qtm.is_fs_outdated()) {
    qtm.calc_final_states();
  }
}

double qtm_data::calc_avg_queue(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  std::uint64_t i = 1;
  double res = 0.;
  for (auto &state :
       // just slicing { final_states[channel_count+1:] }
       ([](std::vector<double> vec, std::size_t f) -> std::vector<double> {
         return std::vector<double>(vec.begin() + f, vec.end());
       })(qtm.final_states(), qtm.channel_count() + 1)) {
    res += i * state;
    i = clamp<std::uint64_t>(i + 1, 1, qtm.queue_size());
  }
  return res;
};

double qtm_data::calc_ete(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  std::uint64_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += i * state;
    i = clamp<std::uint64_t>(i + 1, 0, qtm.channel_count());
  }
  res /= qtm.channel_count();
  return res;
};

double qtm_data::calc_avg_time_queue(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  return qtm_data::calc_avg_queue(qtm) / qtm.channel_count() * qtm.mu();
};

double qtm_data::calc_perc_served_req(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  return 1. - qtm.final_states().back();
};

double qtm_data::calc_avg_count_served_req(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  std::uint64_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += state * i;
    if (i < qtm.channel_count() + 1) {
      ++i;
    }
  }
  return res;
};

double qtm_data::calc_avg_count_req(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  std::uint64_t i = 0;
  double res = 0.;
  for (auto &state : qtm.final_states()) {
    res += state * i;
    ++i;
  }
  return res;
};

double qtm_data::calc_avg_count_unserved_req(qtm &qtm) {
  qtm_data::calc_fs_if_outdated(qtm);

  return qtm_data::calc_avg_count_req(qtm) - qtm_data::calc_avg_count_served_req(qtm);
};

}; // namespace qtm
