#include "Supervisor.hpp"
#include "Common/Base/Interface/Lang.hpp"
#include "Common/Types/Primitives/Inc.hpp"



extern "C" Void app_main() {

    mut supervisor = app::Supervisor();

    supervisor.takeControl();
}
