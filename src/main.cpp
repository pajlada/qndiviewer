#include "application.hpp"

#include <Processing.NDI.Lib.h>

int
main(int argc, char **argv)
{
    if (!NDIlib_initialize()) {
        return 1;
    }

    Application application;

    application.Run();

    NDIlib_destroy();

    return 0;
}
