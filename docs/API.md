# Especificación de API - PS4 Nexus

## 📚 Visión General

PS4 Nexus proporciona una API REST profesional para interactuar con el sistema.

### Base URL

```
https://api.ps4nexus.dev/v1
```

### Autenticación

Todas las solicitudes deben incluir un token JWT en el header:

```
Authorization: Bearer YOUR_JWT_TOKEN
```

## 🔐 Autenticación

### Login

```http
POST /auth/login
Content-Type: application/json

{
    "username": "user@example.com",
    "password": "secure_password"
}
```

**Response (200 OK):**
```json
{
    "success": true,
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
    "expires_in": 3600,
    "user": {
        "id": "usr_123",
        "username": "user@example.com",
        "created_at": "2026-07-01T00:00:00Z"
    }
}
```

### Refresh Token

```http
POST /auth/refresh
Authorization: Bearer YOUR_JWT_TOKEN
```

**Response (200 OK):**
```json
{
    "success": true,
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
    "expires_in": 3600
}
```

### Logout

```http
POST /auth/logout
Authorization: Bearer YOUR_JWT_TOKEN
```

**Response (204 No Content)**

## 👥 Users

### Get User Profile

```http
GET /users/me
Authorization: Bearer YOUR_JWT_TOKEN
```

**Response (200 OK):**
```json
{
    "success": true,
    "data": {
        "id": "usr_123",
        "username": "john_doe",
        "email": "john@example.com",
        "profile_image": "https://...",
        "created_at": "2026-01-15T10:30:00Z",
        "last_login": "2026-07-01T08:45:23Z"
    }
}
```

### Update User Profile

```http
PUT /users/me
Authorization: Bearer YOUR_JWT_TOKEN
Content-Type: application/json

{
    "username": "new_username",
    "email": "new_email@example.com",
    "profile_image": "base64_encoded_image"
}
```

**Response (200 OK):**
```json
{
    "success": true,
    "data": {
        "id": "usr_123",
        "username": "new_username",
        "email": "new_email@example.com"
    }
}
```

## 📊 Data

### Get Data

```http
GET /data?limit=20&offset=0
Authorization: Bearer YOUR_JWT_TOKEN
```

**Response (200 OK):**
```json
{
    "success": true,
    "data": [
        {
            "id": "data_1",
            "name": "Sample Data",
            "created_at": "2026-07-01T10:00:00Z"
        }
    ],
    "pagination": {
        "total": 100,
        "limit": 20,
        "offset": 0
    }
}
```

### Create Data

```http
POST /data
Authorization: Bearer YOUR_JWT_TOKEN
Content-Type: application/json

{
    "name": "New Data",
    "description": "Data description",
    "metadata": {}
}
```

**Response (201 Created):**
```json
{
    "success": true,
    "data": {
        "id": "data_123",
        "name": "New Data",
        "description": "Data description",
        "created_at": "2026-07-01T10:30:00Z"
    }
}
```

### Update Data

```http
PUT /data/{id}
Authorization: Bearer YOUR_JWT_TOKEN
Content-Type: application/json

{
    "name": "Updated Data",
    "description": "Updated description"
}
```

**Response (200 OK):**
```json
{
    "success": true,
    "data": {
        "id": "data_123",
        "name": "Updated Data",
        "updated_at": "2026-07-01T11:00:00Z"
    }
}
```

### Delete Data

```http
DELETE /data/{id}
Authorization: Bearer YOUR_JWT_TOKEN
```

**Response (204 No Content)**

## 🔄 Status Codes

| Code | Meaning | Descripción |
|------|---------|-------------|
| 200 | OK | Solicitud exitosa |
| 201 | Created | Recurso creado exitosamente |
| 204 | No Content | Solicitud exitosa sin contenido |
| 400 | Bad Request | Solicitud inválida |
| 401 | Unauthorized | Autenticación requerida |
| 403 | Forbidden | Acceso denegado |
| 404 | Not Found | Recurso no encontrado |
| 409 | Conflict | Conflicto (p.ej. recurso duplicado) |
| 429 | Too Many Requests | Rate limit excedido |
| 500 | Internal Server Error | Error del servidor |
| 503 | Service Unavailable | Servicio no disponible |

## ⚠️ Error Handling

Todos los errores retornan un formato consistente:

```json
{
    "success": false,
    "error": {
        "code": "INVALID_REQUEST",
        "message": "Descripción del error",
        "details": {
            "field": "username",
            "reason": "must_be_unique"
        }
    }
}
```

### Error Codes

| Code | Descripción |
|------|-------------|
| INVALID_REQUEST | Solicitud malformada |
| AUTHENTICATION_FAILED | Falló autenticación |
| TOKEN_EXPIRED | Token JWT expiró |
| AUTHORIZATION_FAILED | Acceso denegado |
| RESOURCE_NOT_FOUND | Recurso no existe |
| DUPLICATE_RESOURCE | Recurso duplicado |
| INTERNAL_ERROR | Error interno del servidor |
| RATE_LIMITED | Límite de solicitudes excedido |

## 🔗 Rate Limiting

- **Límite**: 1000 solicitudes por hora por usuario
- **Headers de respuesta**:
  - `X-RateLimit-Limit`: 1000
  - `X-RateLimit-Remaining`: 999
  - `X-RateLimit-Reset`: 1625097600

## 📝 Paginación

```http
GET /data?page=1&limit=20&sort=created_at&order=desc
```

**Response:**
```json
{
    "success": true,
    "data": [...],
    "pagination": {
        "page": 1,
        "limit": 20,
        "total": 500,
        "pages": 25
    }
}
```

## 🔍 Filtrado y Búsqueda

```http
GET /data?search=keyword&filter[type]=active&sort=name
```

## 📦 Webhooks

### Registrar Webhook

```http
POST /webhooks
Authorization: Bearer YOUR_JWT_TOKEN
Content-Type: application/json

{
    "url": "https://your-app.com/webhook",
    "events": ["data.created", "data.updated", "data.deleted"],
    "active": true
}
```

### Eventos de Webhook

- `data.created` - Nuevo dato creado
- `data.updated` - Dato actualizado
- `data.deleted` - Dato eliminado
- `user.updated` - Perfil actualizado

## 📚 Ejemplos

### JavaScript/Node.js

```javascript
const axios = require('axios');

const client = axios.create({
    baseURL: 'https://api.ps4nexus.dev/v1',
    headers: {
        'Authorization': `Bearer ${token}`,
        'Content-Type': 'application/json'
    }
});

// Get user profile
client.get('/users/me')
    .then(response => console.log(response.data))
    .catch(error => console.error(error));
```

### Python

```python
import requests

headers = {
    'Authorization': f'Bearer {token}',
    'Content-Type': 'application/json'
}

response = requests.get(
    'https://api.ps4nexus.dev/v1/users/me',
    headers=headers
)

print(response.json())
```

### cURL

```bash
curl -X GET "https://api.ps4nexus.dev/v1/users/me" \
  -H "Authorization: Bearer YOUR_JWT_TOKEN" \
  -H "Content-Type: application/json"
```

## 🔐 Mejores Prácticas

1. **Siempre usar HTTPS** - Nunca transmitas tokens por HTTP
2. **Rotar tokens regularmente** - Implementa refresh token flow
3. **Validar respuestas** - Verifica siempre `success` y `error`
4. **Manejo de errores** - Implementa reintentos con backoff
5. **Logging** - Registra errores pero no tokens
6. **Rate limiting** - Respeta los límites de solicitudes

---

**Especificación de API Versión:** 1.0.0  
**Última actualización:** 2026-07-01
