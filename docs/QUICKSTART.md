# ⚡ Quick Start - PS4 Nexus

Comienza en **5 minutos** con PS4 Nexus.

---

## 🪟 Windows (EXE)

### Instalación Rápida (3 pasos)

```powershell
# 1️⃣ Descargar
curl -L -o PS4-Nexus.zip https://github.com/miqueas80martin-oss/PS4-Nexus/releases/latest/download/PS4-Nexus-Windows-x64.zip

# 2️⃣ Extraer
Expand-Archive PS4-Nexus.zip -DestinationPath C:\PS4Nexus

# 3️⃣ Ejecutar
C:\PS4Nexus\ps4-nexus.exe
```

**O más simple:**
1. Descarga el ZIP desde [Releases](https://github.com/miqueas80martin-oss/PS4-Nexus/releases)
2. Click derecho → "Extraer aquí"
3. Doble clic en `ps4-nexus.exe`

✅ **¡Listo!** Abre http://localhost:8080

---

## 🐧 Linux

### Instalación Rápida (3 pasos)

```bash
# 1️⃣ Descargar y extraer
wget https://github.com/miqueas80martin-oss/PS4-Nexus/releases/latest/download/PS4-Nexus-Linux-x64.tar.gz
tar -xzf PS4-Nexus-Linux-x64.tar.gz

# 2️⃣ Permisos
chmod +x ps4-nexus

# 3️⃣ Ejecutar
./ps4-nexus
```

**Para instalación global:**
```bash
sudo mv ps4-nexus /usr/local/bin/
ps4-nexus  # Ejecutar desde cualquier lugar
```

✅ **¡Listo!** Abre http://localhost:8080

---

## 🍎 macOS

### Instalación Rápida (3 pasos)

```bash
# 1️⃣ Descargar y extraer
curl -L -o PS4-Nexus.tar.gz https://github.com/miqueas80martin-oss/PS4-Nexus/releases/latest/download/PS4-Nexus-macOS-x64.tar.gz
tar -xzf PS4-Nexus.tar.gz

# 2️⃣ Permisos
chmod +x ps4-nexus

# 3️⃣ Ejecutar
./ps4-nexus
```

**Para instalación global:**
```bash
sudo mv ps4-nexus /usr/local/bin/
ps4-nexus  # Ejecutar desde cualquier lugar
```

✅ **¡Listo!** Abre http://localhost:8080

---

## 📱 Android (APK)

### Instalación Rápida (2 pasos)

1. **Descarga** `PS4-Nexus-Android-release.apk` desde [Releases](https://github.com/miqueas80martin-oss/PS4-Nexus/releases)

2. **Abre el archivo** en tu dispositivo Android
   - El archivo se abrirá automáticamente
   - Toca "Instalar"
   - ¡Listo!

✅ La app aparecerá en tu launcher

---

## 🚀 Primeros Pasos

### 1. Verificar que está corriendo

```bash
# Ver versión
ps4-nexus --version

# Ver ayuda
ps4-nexus --help
```

### 2. Acceder a la interfaz

- Abre tu navegador
- Ve a `http://localhost:8080`
- ¡Hola PS4 Nexus! 👋

### 3. Configuración inicial

```bash
# Crear archivo de configuración
ps4-nexus --init

# Iniciar con configuración personalizada
ps4-nexus --config /ruta/a/config.json
```

### 4. Ver logs

```bash
# Mostrar logs en tiempo real
ps4-nexus --verbose

# Guardar logs en archivo
ps4-nexus --log-file ps4-nexus.log
```

---

## 📚 Próximos Pasos

### Usuarios Principiantes
- 📖 Lee el [README completo](README.md)
- 🔗 Explora la [API](API.md)
- ⚙️ Aprende sobre [Configuración](DEVELOPMENT.md)

### Desarrolladores
- 🏗️ [Guía de Arquitectura](ARCHITECTURE.md)
- 🤝 [Cómo Contribuir](../CONTRIBUTING.md)
- 🔒 [Política de Seguridad](SECURITY.md)

### Instalación Avanzada
- 💻 [Instalación desde código fuente](INSTALL.md#-desde-código-fuente)
- 🔧 [Guía de desarrollo](DEVELOPMENT.md)
- 📦 [Crear releases](RELEASES.md)

---

## ⚙️ Configuración Básica

### Variables de Entorno

```bash
# Puerto (default: 8080)
export PS4_PORT=3000

# Modo debug
export PS4_DEBUG=true

# Log level
export PS4_LOG_LEVEL=debug

# Ruta de base de datos
export PS4_DB_PATH=/custom/path/db.sqlite
```

### Archivo de Configuración

Crea `config.json`:
```json
{
  "port": 8080,
  "debug": false,
  "log_level": "info",
  "database": {
    "path": "./data/ps4.db",
    "type": "sqlite"
  },
  "auth": {
    "jwt_secret": "your-secret-key",
    "token_expiry": 3600
  }
}
```

Ejecutar con config:
```bash
ps4-nexus --config config.json
```

---

## 🐛 Solución Rápida de Problemas

### No se inicia

```bash
# Verificar que el puerto 8080 está libre
# Windows:
netstat -ano | findstr :8080

# Linux/macOS:
lsof -i :8080

# Si está ocupado, cambiar puerto
ps4-nexus --port 3000
```

### "Permission denied" (Linux/macOS)

```bash
chmod +x ps4-nexus
```

### "Visual C++ Runtime" (Windows)

Descarga [Visual C++ Redistributable](https://support.microsoft.com/en-us/help/2977003)

### APK no instala (Android)

1. Habilita "Aplicaciones de fuentes desconocidas" en Configuración
2. Libera espacio (necesita 100MB+)
3. Intenta nuevamente

---

## 📞 Necesitas Ayuda?

- 🐛 [Reportar bug](https://github.com/miqueas80martin-oss/PS4-Nexus/issues/new?template=bug_report.md)
- 💡 [Solicitar feature](https://github.com/miqueas80martin-oss/PS4-Nexus/issues/new?template=feature_request.md)
- 💬 [Hacer pregunta](https://github.com/miqueas80martin-oss/PS4-Nexus/discussions)
- 📧 Escribir a: support@ps4nexus.dev

---

## 🎉 ¡Bienvenido!

Ya tienes PS4 Nexus corriendo. Ahora:

- ✅ Explora la interfaz web
- ✅ Lee la documentación
- ✅ Configura según tus necesidades
- ✅ ¡Diviértete!

**Para más información**: [Documentación Completa](README.md)

---

**Versión**: 1.0.0  
**Última actualización**: 2026-07-01  
**Licencia**: MIT
