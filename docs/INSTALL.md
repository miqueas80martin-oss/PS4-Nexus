# 🚀 Guía de Instalación - PS4 Nexus

Aprende cómo instalar PS4 Nexus en tu plataforma preferida.

## 📋 Tabla de Contenidos

- [Windows](#-windows)
- [Linux](#-linux)
- [macOS](#-macos)
- [Android](#-android)
- [Desde Código Fuente](#-desde-código-fuente)
- [Troubleshooting](#-troubleshooting)

---

## 🪟 Windows

### Requisitos Previos

- **OS**: Windows 10/11 (64-bit)
- **RAM**: 2GB mínimo
- **Espacio**: 500MB disponible
- **Runtime**: No requiere instalación adicional

### Instalación Rápida (Recomendado)

#### Opción 1: Descarga Directa

1. **Descarga el archivo**
   - Ve a [GitHub Releases](https://github.com/miqueas80martin-oss/PS4-Nexus/releases)
   - Descarga `PS4-Nexus-Windows-x64.zip`

2. **Extrae el archivo**
   ```powershell
   # Click derecho en el ZIP → "Extraer aquí"
   # O usando PowerShell:
   Expand-Archive PS4-Nexus-Windows-x64.zip -DestinationPath C:\PS4Nexus
   ```

3. **Ejecuta la aplicación**
   - Navega a la carpeta extraída
   - Haz doble clic en `ps4-nexus.exe`
   - ¡Listo! La aplicación se abrirá

#### Opción 2: Línea de Comandos (CMD/PowerShell)

```cmd
REM Descargar
curl -L -o PS4-Nexus.zip https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Windows-x64.zip

REM Extraer
Expand-Archive PS4-Nexus.zip -DestinationPath C:\PS4Nexus

REM Ejecutar
C:\PS4Nexus\ps4-nexus.exe
```

### Crear Acceso Directo (Opcional)

1. **Click derecho en `ps4-nexus.exe`**
2. **Enviar a → Escritorio (crear acceso directo)**
3. Ahora puedes ejecutar desde el escritorio

### Agregar a PATH (Avanzado)

Para ejecutar desde cualquier ubicación:

```powershell
# Como Administrador
$path = "C:\PS4Nexus"
$env:Path += ";$path"
setx Path "%Path%;$path"

# Luego reinicia PowerShell y ejecuta:
ps4-nexus
```

### Desinstalación

```powershell
# Simplemente elimina la carpeta
Remove-Item -Recurse C:\PS4Nexus
```

---

## 🐧 Linux

### Requisitos Previos

- **OS**: Ubuntu 18.04+, Debian 10+, Fedora 30+, CentOS 8+ o similar
- **RAM**: 2GB mínimo
- **Espacio**: 500MB disponible
- **Librerías**: GCC runtime (generalmente incluidas)

### Instalación Rápida

#### Opción 1: Desde Releases (Recomendado)

```bash
# 1. Descargar
wget https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Linux-x64.tar.gz

# O con curl
curl -L -o PS4-Nexus-Linux-x64.tar.gz https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Linux-x64.tar.gz

# 2. Extraer
tar -xzf PS4-Nexus-Linux-x64.tar.gz -C ~/ps4-nexus

# 3. Hacer ejecutable
chmod +x ~/ps4-nexus/ps4-nexus

# 4. Ejecutar
~/ps4-nexus/ps4-nexus
```

#### Opción 2: Instalación Global

```bash
# Crear directorio de instalación
sudo mkdir -p /opt/ps4-nexus

# Descargar y extraer
cd /opt/ps4-nexus
sudo wget https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Linux-x64.tar.gz
sudo tar -xzf PS4-Nexus-Linux-x64.tar.gz
sudo chmod +x ps4-nexus

# Crear symlink en /usr/local/bin
sudo ln -s /opt/ps4-nexus/ps4-nexus /usr/local/bin/ps4-nexus

# Ahora puedes ejecutar desde cualquier lugar
ps4-nexus
```

#### Opción 3: Script de Instalación Automática

```bash
#!/bin/bash
# save as: install.sh

set -e

echo "📥 Instalando PS4 Nexus..."

# Descargar
wget -q https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Linux-x64.tar.gz

# Crear directorio
mkdir -p ~/.local/bin/ps4-nexus

# Extraer
tar -xzf PS4-Nexus-Linux-x64.tar.gz -C ~/.local/bin/ps4-nexus
chmod +x ~/.local/bin/ps4-nexus/ps4-nexus

# Agregar a PATH si es necesario
if ! grep -q "$HOME/.local/bin" ~/.bashrc; then
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
    source ~/.bashrc
fi

# Limpiar
rm PS4-Nexus-Linux-x64.tar.gz

echo "✅ PS4 Nexus instalado en ~/.local/bin/ps4-nexus"
echo "🚀 Ejecuta: ps4-nexus"
```

Ejecutar:
```bash
chmod +x install.sh
./install.sh
```

### Crear Aplicación de Escritorio (Opcional)

```bash
# Crear archivo .desktop
cat > ~/.local/share/applications/ps4-nexus.desktop <<EOF
[Desktop Entry]
Type=Application
Name=PS4 Nexus
Exec=/opt/ps4-nexus/ps4-nexus
Icon=applications-multimedia
Categories=Utility;
EOF

# Actualizar cache
update-desktop-database ~/.local/share/applications/
```

### Verificar Instalación

```bash
ps4-nexus --version
ps4-nexus --help
```

### Desinstalación

```bash
# Si está en /opt
sudo rm -rf /opt/ps4-nexus
sudo rm /usr/local/bin/ps4-nexus

# Si está en ~/.local
rm -rf ~/.local/bin/ps4-nexus

# Remover aplicación de escritorio
rm ~/.local/share/applications/ps4-nexus.desktop
```

---

## 🍎 macOS

### Requisitos Previos

- **OS**: macOS 10.13+ (High Sierra o superior)
- **Arquitectura**: Intel x64 (M1/M2 necesita traducción Rosetta)
- **RAM**: 2GB mínimo
- **Espacio**: 500MB disponible

### Instalación Rápida

#### Opción 1: Desde Terminal (Recomendado)

```bash
# 1. Descargar
curl -L -o PS4-Nexus-macOS-x64.tar.gz https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-macOS-x64.tar.gz

# 2. Extraer
mkdir -p ~/Applications/ps4-nexus
tar -xzf PS4-Nexus-macOS-x64.tar.gz -C ~/Applications/ps4-nexus

# 3. Hacer ejecutable
chmod +x ~/Applications/ps4-nexus/ps4-nexus

# 4. Ejecutar
~/Applications/ps4-nexus/ps4-nexus
```

#### Opción 2: Instalación Global

```bash
# Instalación para todo el sistema (requiere sudo)
sudo mkdir -p /Applications/ps4-nexus
sudo tar -xzf PS4-Nexus-macOS-x64.tar.gz -C /Applications/ps4-nexus
sudo chmod +x /Applications/ps4-nexus/ps4-nexus

# Crear symlink
sudo ln -s /Applications/ps4-nexus/ps4-nexus /usr/local/bin/ps4-nexus

# Ejecutar
ps4-nexus
```

#### Opción 3: Installer Script

```bash
#!/bin/bash
# save as: install-macos.sh

echo "📥 Instalando PS4 Nexus en macOS..."

# Descargar
echo "⬇️  Descargando..."
curl -L -o PS4-Nexus-macOS-x64.tar.gz https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-macOS-x64.tar.gz

# Crear directorio
echo "📁 Creando directorio..."
mkdir -p ~/Applications/ps4-nexus

# Extraer
echo "📦 Extrayendo..."
tar -xzf PS4-Nexus-macOS-x64.tar.gz -C ~/Applications/ps4-nexus
chmod +x ~/Applications/ps4-nexus/ps4-nexus

# Crear alias en .bash_profile o .zshrc
if [ -n "$ZSH_VERSION" ]; then
    shell_rc="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
    shell_rc="$HOME/.bash_profile"
fi

if ! grep -q "alias ps4-nexus" "$shell_rc" 2>/dev/null; then
    echo "alias ps4-nexus='~/Applications/ps4-nexus/ps4-nexus'" >> "$shell_rc"
fi

# Limpiar
rm PS4-Nexus-macOS-x64.tar.gz

echo "✅ PS4 Nexus instalado!"
echo "🚀 Ejecuta: ps4-nexus"
echo "   O: ~/Applications/ps4-nexus/ps4-nexus"
```

Ejecutar:
```bash
chmod +x install-macos.sh
./install-macos.sh
```

### Crear Aplicación Launchpad

```bash
# Crear aplicación .app
mkdir -p PS4Nexus.app/Contents/MacOS
mkdir -p PS4Nexus.app/Contents/Resources

# Copiar binario
cp ~/Applications/ps4-nexus/ps4-nexus PS4Nexus.app/Contents/MacOS/

# Crear Info.plist
cat > PS4Nexus.app/Contents/Info.plist <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleName</key>
    <string>PS4 Nexus</string>
    <key>CFBundleVersion</key>
    <string>1.0.0</string>
    <key>CFBundleExecutable</key>
    <string>ps4-nexus</string>
</dict>
</plist>
EOF

# Mover a Applications
mv PS4Nexus.app ~/Applications/
```

### M1/M2 Compatibility (Apple Silicon)

```bash
# Instalar Rosetta 2 (si no lo tiene)
softwareupdate --install-rosetta

# Ejecutar bajo Rosetta
arch -x86_64 ~/Applications/ps4-nexus/ps4-nexus
```

### Desinstalación

```bash
# Opción 1: Usuario actual
rm -rf ~/Applications/ps4-nexus

# Opción 2: Sistema completo
sudo rm -rf /Applications/ps4-nexus
sudo rm /usr/local/bin/ps4-nexus

# Opción 3: Si usas alias, remover de .zshrc/.bash_profile
sed -i '' '/alias ps4-nexus/d' ~/.zshrc
```

---

## 📱 Android

### Requisitos Previos

- **OS**: Android 8.0 (API 26) o superior
- **RAM**: 1GB mínimo
- **Espacio**: 100MB disponible
- **Permisos**: Permitir instalación desde fuentes desconocidas

### Instalación Rápida

#### Opción 1: Instalación Directa (Recomendado)

1. **En tu PC/Mac:**
   - Descarga `PS4-Nexus-Android-release.apk` desde [GitHub Releases](https://github.com/miqueas80martin-oss/PS4-Nexus/releases)

2. **Transfiere a tu dispositivo:**
   ```bash
   # Por USB
   - Conecta el teléfono por USB
   - Arrastra el APK al almacenamiento del dispositivo
   
   # Por email/Telegram/Drive
   - Envía el APK a tu email o Telegram
   - Descarga en el dispositivo
   ```

3. **En tu dispositivo Android:**
   - Abre el archivo manager
   - Navega donde guardaste el APK
   - Toca el archivo `PS4-Nexus-Android-release.apk`
   - Toca "Instalar"
   - ¡Listo! La app aparecerá en tu launcher

#### Opción 2: Habilitar Fuentes Desconocidas (Primero)

Si obtienes un aviso de "fuentes desconocidas":

1. **Abre Configuración**
2. **Seguridad** → **Aplicaciones desconocidas** (o similar)
3. **Habilita la opción**
4. Regresa a instalar el APK

#### Opción 3: ADB (Android Debug Bridge)

```bash
# En tu PC/Mac con SDK instalado

# 1. Conecta el dispositivo por USB
adb devices

# 2. Instala el APK
adb install PS4-Nexus-Android-release.apk

# 3. Inicia la aplicación
adb shell am start -n com.ps4nexus/.MainActivity
```

#### Opción 4: Play Store (Próximamente)

Una vez publicada, podrás instalar directamente desde Google Play Store.

### Verificar Instalación

- La aplicación aparece en tu launcher/app drawer
- Puedes buscarla por "PS4 Nexus"
- Toca el icono para abrir

### Desinstalación

- **Opción 1**: Mantén presionado el icono de la app → Desinstalar
- **Opción 2**: Configuración → Aplicaciones → PS4 Nexus → Desinstalar
- **Opción 3**: Línea de comandos
  ```bash
  adb uninstall com.ps4nexus
  ```

---

## 💻 Desde Código Fuente

### Requisitos Previos

```bash
# Windows, Linux y macOS requieren:
- Git >= 2.30
- CMake >= 3.15
- C++ Compiler (GCC 9+, Clang 10+, MSVC 2019+)
- Node.js >= 16
- npm >= 7
```

### Instalación Detallada

#### Paso 1: Clonar el Repositorio

```bash
git clone https://github.com/miqueas80martin-oss/PS4-Nexus.git
cd PS4-Nexus
```

#### Paso 2: Instalar Dependencias

```bash
# Instalar dependencias Node
npm install

# Configurar pre-commit hooks
npm run setup:hooks
```

#### Paso 3: Compilar

```bash
# Build Release (Optimizado)
npm run build

# O build Debug (Para desarrollo)
npm run build:debug
```

#### Paso 4: Ejecutar

```bash
# Ejecutar directamente
./build/bin/ps4-nexus

# O en Windows
.\build\bin\ps4-nexus.exe

# O en macOS/Linux con ruta completa
~/PS4-Nexus/build/bin/ps4-nexus
```

#### Paso 5: Tests (Opcional)

```bash
npm run test
```

### Compilación por Sistema Operativo

#### Windows (Visual Studio)

```powershell
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cd ..
.\build\bin\ps4-nexus.exe
```

#### Linux

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release -j$(nproc)
cd ..
./build/bin/ps4-nexus
```

#### macOS

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release -j$(sysctl -n hw.ncpu)
cd ..
./build/bin/ps4-nexus
```

---

## 🔐 Verificar Integridad de Descargas

Después de descargar, verifica que no fue modificado:

### Linux/macOS

```bash
# Descargar checksums
wget https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/checksums.txt

# Verificar
sha256sum -c checksums.txt
```

### Windows (PowerShell)

```powershell
# Calcular hash
Get-FileHash PS4-Nexus-Windows-x64.zip -Algorithm SHA256

# Comparar con el publicado
# (Los hashes deben coincidir)
```

---

## 🐛 Troubleshooting

### Windows

#### Problema: "No se puede encontrar el archivo"
```
Solución:
- Asegúrate de que extraiste TODO el ZIP
- Verifica que ps4-nexus.exe esté en la carpeta
```

#### Problema: "Windows protegió tu PC"
```
Solución:
- Click en "Más información"
- Click en "Ejecutar de todas formas"
- Esto es normal para programas no firmados
```

#### Problema: "Visual C++ Runtime not found"
```
Solución:
- Descarga: https://support.microsoft.com/en-us/help/2977003
- Instala Visual C++ Redistributable
```

### Linux

#### Problema: "Permiso denegado"
```bash
Solución:
chmod +x ps4-nexus
./ps4-nexus
```

#### Problema: "Librería no encontrada (libstdc++.so)"
```bash
Solución:
# Ubuntu/Debian
sudo apt-get install libstdc++6

# Fedora
sudo dnf install libstdc++-devel
```

### macOS

#### Problema: "No se puede abrir porque es de un desarrollador no identificado"
```
Solución:
- Derecha en ps4-nexus → Abrir
- Confirma "Abrir"
- O usa: xattr -d com.apple.quarantine ps4-nexus
```

### Android

#### Problema: "No se puede instalar"
```
Solución:
1. Verifica que tienes espacio (100MB+)
2. Habilita "Fuentes desconocidas" en Seguridad
3. Intenta desinstalar versión anterior si existe
4. Reinicia el dispositivo
```

---

## ✅ Verificar Instalación

Después de instalar, verifica que funciona:

```bash
# Windows
ps4-nexus.exe --version

# Linux
ps4-nexus --version

# macOS
ps4-nexus --version

# Android
Abre la aplicación desde el launcher
```

---

## 📞 Soporte

¿Problemas durante la instalación?

- 🐛 [Reporta un bug](https://github.com/miqueas80martin-oss/PS4-Nexus/issues/new?template=bug_report.md)
- 💬 [Abre una discusión](https://github.com/miqueas80martin-oss/PS4-Nexus/discussions)
- 📖 [Lee la documentación](https://github.com/miqueas80martin-oss/PS4-Nexus/blob/main/README.md)

---

**Última actualización:** 2026-07-01  
**Versión Actual:** 1.0.0
