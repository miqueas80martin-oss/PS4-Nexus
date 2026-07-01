# 🛠️ Guía de Desarrollo Móvil

## Compilación para Android

```bash
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=$NDK_PATH/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-21
```

## Compilación para iOS

```bash
cmake .. \
  -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_OSX_ARCHITECTURES=arm64
```

## Dispositivos Testeados
- ✅ Xiaomi Redmi Note 9
- ✅ Samsung Galaxy A12
- ✅ Poco F3
- ✅ OnePlus 9
- ✅ iPhone 12
