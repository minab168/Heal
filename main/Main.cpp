#include "Common/Base/Interface/Lang.hpp"
#include "Common/Types/Primitives/Inc.hpp"
#include "Supervisor/Supervisor.hpp"
#include "Tasks.hpp"



extern "C" Void app_main() {

    mut supervisor = app::Supervisor(task_table);

    supervisor.takeControl();
}
