#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLE_NAME 50
#define MAX_VEHICLE_COUNT 100

// 1
typedef struct {
    int id;
    char license_plate[MAX_VEHICLE_NAME];
    char model[MAX_VEHICLE_NAME];
    char color[MAX_VEHICLE_NAME];
} Vehicle;

typedef struct {
    Vehicle vehicles[MAX_VEHICLE_COUNT];
    int count;
} VehicleSystem;
// 初始化车辆管理系统
void initSystem(VehicleSystem *system) {
    system->count = 0;
}

// 添加车辆信息
void addVehicle(VehicleSystem *system, int id, const char *license_plate, const char *model, const char *color) {
    if (system->count >= MAX_VEHICLE_COUNT) {
        printf("车辆管理系统已满，无法添加新的车辆。\n");
        return;
    }

    Vehicle new_vehicle = {id, "", "", ""};
    strncpy(new_vehicle.license_plate, license_plate, MAX_VEHICLE_NAME);
    strncpy(new_vehicle.model, model, MAX_VEHICLE_NAME);
    strncpy(new_vehicle.color, color, MAX_VEHICLE_NAME);

    system->vehicles[system->count++] = new_vehicle;
    printf("车辆添加成功。\n");
}

// 删除车辆信息
void deleteVehicle(VehicleSystem *system, int id) {
    int found = 0;
    for (int i = 0; i < system->count; i++) {
        if (system->vehicles[i].id == id) {
            found = 1;
            for (int j = i; j < system->count - 1; j++) {
                system->vehicles[j] = system->vehicles[j + 1];
            }
            system->count--;
            printf("车辆删除成功。\n");
            break;
        }
    }

    if (!found) {
        printf("未找到ID为%d的车辆。\n", id);
    }
}

// 查询车辆信息
void queryVehicle(VehicleSystem *system, int id) {
    for (int i = 0; i < system->count; i++) {
        if (system->vehicles[i].id == id) {
            printf("车辆信息：\n");
            printf("ID: %d\n", system->vehicles[i].id);
            printf("车牌号: %s\n", system->vehicles[i].license_plate);
            printf("型号: %s\n", system->vehicles[i].model);
            printf("颜色: %s\n", system->vehicles[i].color);
            return;
        }
    }
    printf("未找到ID为%d的车辆。\n", id);
}
int main() {
    VehicleSystem system;
    initSystem(&system);

    int choice, id;
    char license_plate[MAX_VEHICLE_NAME], model[MAX_VEHICLE_NAME], color[MAX_VEHICLE_NAME];

    while (1) {
        printf("车辆管理系统\n");
        printf("1. 添加车辆\n");
        printf("2. 删除车辆\n");
        printf("3. 查询车辆\n");
        printf("4. 退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入车辆ID：");
                scanf("%d", &id);
                printf("请输入车牌号：");
                scanf("%s", license_plate);
                printf("请输入车辆型号：");
                scanf("%s", model);
                printf("请输入车辆颜色：");
                scanf("%s", color);
                addVehicle(&system, id, license_plate, model, color);
                break;
            case 2:
                printf("请输入要删除车辆的ID：");
                scanf("%d", &id);
                deleteVehicle(&system, id);
                break;
            case 3:
                printf("请输入要查询车辆的ID：");
                scanf("%d", &id);
                queryVehicle(&system, id);
                break;
            case 4:
                exit(0);
            default:
                printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
}