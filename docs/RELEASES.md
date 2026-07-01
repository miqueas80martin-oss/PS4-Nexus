# Guía de Releases - PS4 Nexus

## 📦 Cómo Crear una Release

### Opción 1: Automático con GitHub Actions

1. **Crear un tag**
   ```bash
   git tag -a v1.0.0 -m "Release version 1.0.0"
   git push origin v1.0.0
   ```

2. **GitHub Actions compilará automáticamente** y creará la release con:
   - Windows EXE (.zip)
   - Linux Binary (.tar.gz)
   - macOS Binary (.tar.gz)
   - Android APK
   - Checksums SHA256

### Opción 2: Manual

1. **Preparar la release localmente**
   ```bash
   # Hacer el script ejecutable
   chmod +x scripts/release.sh
   
   # Correr script de release
   ./scripts/release.sh v1.0.0
   ```

2. **Crear release en GitHub**
   ```bash
   # Crear tag
   git tag -a v1.0.0 -m "Release v1.0.0"
   git push origin v1.0.0
   ```

3. **Subir archivos a la release**
   - Ve a GitHub → Releases
   - Click en "Create release"
   - Selecciona el tag `v1.0.0`
   - Carga los archivos desde `release/v1.0.0/`
   - Escribe la descripción (changelog)
   - Publica la release

## 📋 Archivos en las Releases

### Windows
```
PS4-Nexus-Windows-x64-v1.0.0.zip
├── ps4-nexus.exe (ejecutable principal)
├── README.txt
└── LICENSE
```

**Requisitos:**
- Windows 10/11 64-bit
- 2GB RAM mínimo
- .NET Runtime (si aplica)

**Instalación:**
1. Extrae el ZIP
2. Ejecuta `ps4-nexus.exe`

### Linux
```
PS4-Nexus-Linux-x64-v1.0.0.tar.gz
├── ps4-nexus (ejecutable)
├── README.txt
└── LICENSE
```

**Requisitos:**
- Linux x64 (Ubuntu 18.04+, Debian 10+, etc.)
- GCC Runtime libraries
- 2GB RAM mínimo

**Instalación:**
```bash
tar -xzf PS4-Nexus-Linux-x64-v1.0.0.tar.gz
chmod +x ps4-nexus
./ps4-nexus
```

### macOS
```
PS4-Nexus-macOS-x64-v1.0.0.tar.gz
├── ps4-nexus (ejecutable)
├── README.txt
└── LICENSE
```

**Requisitos:**
- macOS 10.13 o superior
- Architecture: Intel x64
- 2GB RAM mínimo

**Instalación:**
```bash
tar -xzf PS4-Nexus-macOS-x64-v1.0.0.tar.gz
chmod +x ps4-nexus
./ps4-nexus
```

### Android
```
PS4-Nexus-Android-v1.0.0.apk
```

**Requisitos:**
- Android 8.0 o superior
- 100MB espacio libre
- 1GB RAM mínimo

**Instalación:**
1. Descarga el APK
2. Habilita "Instalar desde fuentes desconocidas"
3. Abre el APK para instalar
4. O usa: `adb install PS4-Nexus-Android-v1.0.0.apk`

## 🔐 Verificar Integridad

### Descargar checksums
```bash
# Los checksums están en el archivo checksums-v1.0.0.txt
```

### Verificar en Linux/macOS
```bash
sha256sum -c checksums-v1.0.0.txt
```

### Verificar en Windows (PowerShell)
```powershell
Get-FileHash PS4-Nexus-Windows-x64-v1.0.0.zip -Algorithm SHA256
```

## 📝 Convención de Versiones

Seguimos **Semantic Versioning** (SemVer):

```
MAJOR.MINOR.PATCH-PRERELEASE+BUILD

v1.2.3-beta.1+build.123
```

### Ejemplos
- `v1.0.0` - Primera versión estable
- `v1.1.0` - Nueva feature compatible
- `v1.0.1` - Bug fix
- `v2.0.0` - Cambios incompatibles
- `v1.0.0-alpha` - Versión alpha
- `v1.0.0-beta.1` - Versión beta 1
- `v1.0.0-rc.1` - Release candidate 1

## 🔄 Workflow de Release

```
1. Desarrollo en 'develop'
   ↓
2. Crear rama 'release/v1.0.0'
   ├─ Bump version
   ├─ Update CHANGELOG.md
   ├─ Tests finales
   ↓
3. Merge a 'main'
   ├─ Code review
   ├─ Build final
   ↓
4. Crear tag 'v1.0.0'
   ├─ GitHub Actions compila
   ├─ Genera binarios
   ↓
5. Publicar Release
   ├─ Agrega cambios
   ├─ Agrega binarios
   ├─ Publica
```

## 📊 Checklist Pre-Release

- [ ] Código merged a `main`
- [ ] Todos los tests pasan
- [ ] Documentación actualizada
- [ ] CHANGELOG.md actualizado
- [ ] Version bumped (package.json, CMakeLists.txt)
- [ ] README.md con instrucciones
- [ ] Security audit completo
- [ ] Performance tested
- [ ] No warnings en compilation
- [ ] Tag creado localmente
- [ ] Git push del tag

## 🚀 Publicar Release

### Paso 1: Preparar el código
```bash
# Actualizar versión
# - src/CMakeLists.txt
# - package.json
# - docs/CHANGELOG.md
git add .
git commit -m "chore: bump version to v1.0.0"
```

### Paso 2: Crear el tag
```bash
git tag -a v1.0.0 -m "Release v1.0.0"
git push origin main
git push origin v1.0.0
```

### Paso 3: GitHub Actions
- Automáticamente compilará para todos los SO
- Generará los binarios
- Creará la release en GitHub

### Paso 4: Verificar y publicar
- Ve a GitHub → Releases
- Verifica que los binarios estén presentes
- Revisa la descripción
- Publica si todo está correcto

## 📥 Instalación desde Release

### Windows
```bash
# 1. Descarga PS4-Nexus-Windows-x64-v1.0.0.zip
# 2. Extrae
# 3. Ejecuta ps4-nexus.exe
```

### Linux
```bash
wget https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-Linux-x64-v1.0.0.tar.gz
tar -xzf PS4-Nexus-Linux-x64-v1.0.0.tar.gz
./ps4-nexus
```

### macOS
```bash
curl -L -o PS4-Nexus-macOS-x64-v1.0.0.tar.gz https://github.com/miqueas80martin-oss/PS4-Nexus/releases/download/v1.0.0/PS4-Nexus-macOS-x64-v1.0.0.tar.gz
tar -xzf PS4-Nexus-macOS-x64-v1.0.0.tar.gz
./ps4-nexus
```

## 🆚 Comparar Releases

```bash
git log v0.9.0..v1.0.0 --oneline
```

## 🗂️ Mantener Releases

### Borrar una release local
```bash
git tag -d v1.0.0
```

### Borrar una release remota
```bash
git push origin --delete v1.0.0
```

## 📞 Soporte

- 📧 Email: support@ps4nexus.dev
- 🐛 Issues: https://github.com/miqueas80martin-oss/PS4-Nexus/issues
- 💬 Discussions: https://github.com/miqueas80martin-oss/PS4-Nexus/discussions

---

**Última actualización:** 2026-07-01
