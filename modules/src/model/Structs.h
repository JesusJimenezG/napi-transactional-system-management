#pragma once

struct Producto
{
    int id;
    int id_proveedor;
    int stock;
    float precio;
    char descripcion[45];
    int stock_min;
};

struct Proveedor
{
    int id;
    char nombre[45];
    char telefono[30];
};

struct Compra
{
    int id;
    int id_producto;
    int id_factura;
    int cantidad;
};

struct Factura
{
    int id;
    int id_cliente;
    char fecha[12];
};

struct Cliente
{
    int id;
    char nombre[45];
    char direccion[70];
    char telefono[18];
};

// enum Type
// {
//     PRODUCTO = 0,
//     PROVEEDOR = 1,
//     COMPRA = 2,
//     FACTURA = 3,
//     CLIENTE = 4
// };