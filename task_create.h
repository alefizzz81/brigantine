// Andrew Naplavkov

#ifndef TASK_CREATE_H
#define TASK_CREATE_H

#include <QString>
#include <string>
#include <vector>
#include "connection_link.h"
#include "layer_link.h"
#include "task.h"

class task_create : public task {
  Q_OBJECT
  std::vector<layer_link> m_lrs_from;
  connection_link m_dbc_to;
  bool m_sql, m_view;

signals:
  void signal_sql(connection_link dbc, std::vector<std::string> sqls);
  void signal_refresh(connection_link dbc);

public:
  task_create(std::vector<layer_link> lrs_from, connection_link dbc_to, bool sql, bool view);
  void run(progress* prg) override;
}; // task_create

#endif // TASK_CREATE_H
