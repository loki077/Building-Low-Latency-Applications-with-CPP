#include <cstdio>   // For printf function
#include <cstdint>  // For fixed-width integer types
#include <cstddef>  // For offsetof macro

// Struct with poorly aligned data
struct PoorlyAlignedData {
  char c;       // 1 byte
  uint16_t u;   // 2 bytes
  double d;     // 8 bytes
  int16_t i;    // 2 bytes
};

// Struct with well aligned data
struct WellAlignedData {
  double d;     // 8 bytes
  uint16_t u;   // 2 bytes
  int16_t i;    // 2 bytes
  char c;       // 1 byte
};

// Change packing to 1 byte alignment
#pragma pack(push, 1)
struct PackedData {
  double d;     // 8 bytes
  uint16_t u;   // 2 bytes
  int16_t i;    // 2 bytes
  char c;       // 1 byte
};
// Restore previous packing
#pragma pack(pop)

int main() {
  // Print offsets and size of PoorlyAlignedData
  printf("PoorlyAlignedData c:%lu u:%lu d:%lu i:%lu size:%lu\n",
         offsetof(struct PoorlyAlignedData,c), offsetof(struct PoorlyAlignedData,u), offsetof(struct PoorlyAlignedData,d), offsetof(struct PoorlyAlignedData,i), sizeof(PoorlyAlignedData));
  
  // Print offsets and size of WellAlignedData
  printf("WellAlignedData d:%lu u:%lu i:%lu c:%lu size:%lu\n",
         offsetof(struct WellAlignedData,d), offsetof(struct WellAlignedData,u), offsetof(struct WellAlignedData,i), offsetof(struct WellAlignedData,c), sizeof(WellAlignedData));
  
  // Print offsets and size of PackedData
  printf("PackedData d:%lu u:%lu i:%lu c:%lu size:%lu\n",
         offsetof(struct PackedData,d), offsetof(struct PackedData,u), offsetof(struct PackedData,i), offsetof(struct PackedData,c), sizeof(PackedData));
}