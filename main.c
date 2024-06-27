#include <xgboost/c_api.h>

int main() {
     int major, minor, patch;
    XGBoostVersion(&major, &minor, &patch);
    printf("XGBoost version: %d.%d.%d\n", major, minor, patch);

    
    return 0;
}