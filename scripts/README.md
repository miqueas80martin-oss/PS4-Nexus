# Release Scripts - PS4 Nexus

Este directorio contiene scripts para automatizar el proceso de build y release.

## 🚀 Scripts Disponibles

### 1. **release.sh** (Linux/macOS)
Script de shell para construir releases en sistemas Unix.

**Uso:**
```bash
chmod +x scripts/release.sh
./scripts/release.sh v1.0.0
```

**Qué hace:**
- Compila para Windows (si está disponible)
- Compila para Linux
- Compila para macOS (en macOS)
- Genera checksums SHA256
- Crea manifiesto de release

### 2. **release.bat** (Windows)
Script de batch para construir releases en Windows.

**Uso:**
```cmd
scripts\release.bat v1.0.0
```

**Qué hace:**
- Compila para Windows
- Genera checksums
- Crea manifiesto de release

### 3. **release_builder.py** (Multiplataforma)
Script Python para control completo del proceso de release.

**Requisitos:**
```bash
python3 --version  # 3.7+
```

**Uso:**
```bash
python3 scripts/release_builder.py v1.0.0
```

**Ventajas:**
- Funciona en todas las plataformas
- Mejor manejo de errores
- Genera JSON manifest
- Más flexible y extensible

## 📦 Estructura de Release

Después de ejecutar cualquier script, se genera:

```
release/v1.0.0/
├── PS4-Nexus-Windows-x64-v1.0.0.zip
├── PS4-Nexus-Linux-x64-v1.0.0.tar.gz
├── PS4-Nexus-macOS-x64-v1.0.0.tar.gz
├── checksums-v1.0.0.txt
├── manifest-v1.0.0.json
└── MANIFEST-v1.0.0.txt
```

## 🔄 Flujo de Release Recomendado

### Opción A: Automático (Recomendado)

1. **Preparar versión:**
   ```bash
   # Actualizar versión en archivos
   # git add .
   # git commit -m "chore: bump version to v1.0.0"
   ```

2. **Crear tag:**
   ```bash
   git tag -a v1.0.0 -m "Release v1.0.0"
   git push origin v1.0.0
   ```

3. **GitHub Actions:**
   - Se compila automáticamente
   - Se crean binarios
   - Se publica release en GitHub

### Opción B: Local con Script

1. **Ejecutar script:**
   ```bash
   ./scripts/release.sh v1.0.0
   ```

2. **Revisar archivos:**
   ```bash
   ls -la release/v1.0.0/
   ```

3. **Crear tag:**
   ```bash
   git tag -a v1.0.0 -m "Release v1.0.0"
   git push origin v1.0.0
   ```

4. **Subir archivos manualmente** a GitHub Releases

## 📋 Requisitos Previos

### Para todos los scripts:
- CMake >= 3.15
- Compilador C++ (GCC, Clang, MSVC)
- Git

### Para release.sh:
- Bash
- tar y gzip
- sha256sum

### Para release.bat:
- Windows 10/11
- 7-Zip (para compresión)
- certutil (incluido en Windows)

### Para release_builder.py:
- Python 3.7+
- (No requiere dependencias externas)

## 🔒 Verificar Releases

Después de descargar, verifica la integridad:

```bash
# Linux/macOS
sha256sum -c checksums-v1.0.0.txt

# Windows PowerShell
Get-FileHash PS4-Nexus-Windows-x64-v1.0.0.zip -Algorithm SHA256
```

## 📊 Información en los Manifests

### checksums-*.txt
Contiene SHA256 hashes para verificación de integridad:
```
abc123def456... PS4-Nexus-Windows-x64-v1.0.0.zip
def456ghi789... PS4-Nexus-Linux-x64-v1.0.0.tar.gz
```

### manifest-*.json
Archivo JSON con metadatos:
```json
{
  "version": "v1.0.0",
  "release_date": "2026-07-01T00:00:00",
  "binaries": {
    "windows": "PS4-Nexus-Windows-x64.zip",
    "linux": "PS4-Nexus-Linux-x64.tar.gz"
  },
  "checksums": { ... }
}
```

### MANIFEST-*.txt
Versión en texto legible con instrucciones completas.

## 🐛 Troubleshooting

### CMake no se encuentra
```bash
# Instalar CMake
sudo apt install cmake        # Linux
brew install cmake            # macOS
choco install cmake           # Windows (con Chocolatey)
```

### Compilación falla
```bash
# Limpiar builds previos
rm -rf release/v*

# Reintentar
./scripts/release.sh v1.0.0
```

### Permisos denegados en Linux
```bash
chmod +x scripts/release.sh
```

### Python no encontrado
```bash
# Verificar instalación
python3 --version

# En Windows, puede ser 'python' sin el 3
python scripts/release_builder.py v1.0.0
```

## 📝 Personalización

### Agregar plataformas
Edita los scripts para agregar nuevas plataformas (ARM, Alpine, etc.)

### Cambiar ubicación de output
Modifica la variable `release_dir` en los scripts

### Agregar pasos adicionales
- Compresión adicional
- Firmas digitales
- Uploads automáticos a CDN
- Notificaciones

## 🔗 Recursos Útiles

- [CMake Documentation](https://cmake.org/)
- [Semantic Versioning](https://semver.org/)
- [GitHub Releases API](https://docs.github.com/en/repositories/releasing-projects-on-github)

## 💡 Tips

1. **Siempre verifica los builds localmente** antes de publicar
2. **Mantén backups** de las versiones anteriores
3. **Documenta cambios** en CHANGELOG.md
4. **Prueba en múltiples plataformas** si es posible
5. **Usa checksums** para verificar integridad

---

**Última actualización:** 2026-07-01
