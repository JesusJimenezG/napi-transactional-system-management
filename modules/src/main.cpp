#include <napi.h>
#include "controller/Controller.h"
#include "auth/Login.cpp"
#include "model/Structs.h"

using namespace Napi;
using namespace std;

Value InsertProducto(const CallbackInfo &info)
{
    Env env = info.Env();

    if (!info[0].IsObject())
    {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Object obj = info[0].ToObject();
    Array props = obj.GetPropertyNames();

    // for (unsigned int j = 0; j < props.Length(); j++)
    // {
    //     // printf("key: %s: value: %s\n",
    //     //        props.Get(j).ToString().Utf8Value().c_str(),
    //     //        obj.Get(props.Get(j)).ToString().Utf8Value().c_str());
    //     string key = props.Get(j).ToString().Utf8Value();
    //     cout << obj.Get(key).ToString().Utf8Value().c_str() << endl;
    // }

    Producto producto = *new Producto();

    producto.id = obj.Get("id").ToNumber().Int32Value();
    producto.id_proveedor = obj.Get("id_proveedor").ToNumber().Int32Value();
    producto.stock = obj.Get("stock").ToNumber().Int64Value();
    producto.precio = obj.Get("precio").ToNumber().FloatValue();
    string descripcion = obj.Get("descripcion").ToString().Utf8Value();
    if (descripcion.length() > sizeof(producto.descripcion))
    {
        string mssg = "Excedeed maximum size: " +
                      sizeof(producto.descripcion);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    strcpy(producto.descripcion, descripcion.c_str());
    producto.stock_min = obj.Get("stock_min").ToNumber().Int64Value();

    cout << "Producto id: " << producto.id << endl;
    cout << "Producto id_proveedor: " << producto.id_proveedor << endl;
    cout << "Producto stock: " << producto.stock << endl;
    cout << "Producto precio: " << producto.precio << endl;
    cout << "Producto descripcion: " << producto.descripcion << endl;
    cout << "Producto stock_min: " << producto.stock_min << endl;

    Controller<Producto> controller((char *)"Cliente.dat");
    if (!controller.Insert(producto))
    {
        return String::New(env, "Failed");
    }
    return String::New(env, "Successfully inserted");
}

Value InsertProveedor(const CallbackInfo &info)
{
    Env env = info.Env();

    if (!info[0].IsObject())
    {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Object obj = info[0].ToObject();
    Array props = obj.GetPropertyNames();

    Proveedor proveedor = *new Proveedor();

    proveedor.id = obj.Get("id").ToNumber().Int32Value();
    string nombre = obj.Get("nombre").ToString().Utf8Value();
    string telefono = obj.Get("telefono").ToString().Utf8Value();

    if (nombre.length() > sizeof(proveedor.nombre))
    {
        string mssg = "Excedeed maximum size of name: " +
                      sizeof(proveedor.nombre);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (telefono.length() > sizeof(proveedor.telefono))
    {
        string mssg = "Excedeed maximum size of phone: " +
                      sizeof(proveedor.telefono);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    strcpy(proveedor.nombre, nombre.c_str());
    strcpy(proveedor.telefono, telefono.c_str());

    cout << "Proveedor id: " << proveedor.id << endl;
    cout << "Proveedor nombre: " << proveedor.nombre << endl;
    cout << "Proveedor telefono: " << proveedor.telefono << endl;

    Controller<Proveedor> controller((char *)"Proveedor.dat");
    if (!controller.Insert(proveedor))
    {
        return String::New(env, "Failed");
    }
    return String::New(env, "Successfully inserted");
}

Value InsertCompra(const CallbackInfo &info)
{
    Env env = info.Env();

    if (!info[0].IsObject())
    {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Object obj = info[0].ToObject();
    Array props = obj.GetPropertyNames();

    Compra compra = *new Compra();

    compra.id = obj.Get("id").ToNumber().Int32Value();
    compra.id_factura = obj.Get("id_factura").ToNumber().Int32Value();
    compra.id_producto = obj.Get("id_producto").ToNumber().Int32Value();
    compra.cantidad = obj.Get("cantidad").ToNumber().Int32Value();

    cout << "Compra id: " << compra.id << endl;
    cout << "Compra id_factura: " << compra.id_factura << endl;
    cout << "Compra id_producto: " << compra.id_producto << endl;
    cout << "Compra cantidad: " << compra.cantidad << endl;

    Controller<Compra> controller((char *)"Compra.dat");
    if (!controller.Insert(compra))
    {
        return String::New(env, "Failed");
    }
    return String::New(env, "Successfully inserted");
}

Value InsertFactura(const CallbackInfo &info)
{
    Env env = info.Env();

    if (!info[0].IsObject())
    {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Object obj = info[0].ToObject();
    Array props = obj.GetPropertyNames();

    Factura factura = *new Factura();

    factura.id = obj.Get("id").ToNumber().Int32Value();
    factura.id_cliente = obj.Get("id_factura").ToNumber().Int32Value();
    string fecha = obj.Get("fecha").ToString().Utf8Value();

    if (fecha.length() > sizeof(factura.fecha))
    {
        string mssg = "Excedeed maximum size: " +
                      sizeof(factura.fecha);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    strcpy(factura.fecha, fecha.c_str());

    cout << "Factura id: " << factura.id << endl;
    cout << "Factura id_cliente: " << factura.id_cliente << endl;
    cout << "Factura fecha: " << factura.fecha << endl;

    Controller<Factura> controller((char *)"Factura.dat");
    if (!controller.Insert(factura))
    {
        return String::New(env, "Failed");
    }
    return String::New(env, "Successfully inserted");
}

Value InsertCliente(const CallbackInfo &info)
{
    Env env = info.Env();

    if (!info[0].IsObject())
    {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Object obj = info[0].ToObject();
    Array props = obj.GetPropertyNames();

    Cliente cliente = *new Cliente();

    cliente.id = obj.Get("id").ToNumber().Int32Value();
    string nombre = obj.Get("nombre").ToString().Utf8Value();
    string direccion = obj.Get("direccion").ToString().Utf8Value();
    string telefono = obj.Get("telefono").ToString().Utf8Value();
    if (nombre.length() > sizeof(cliente.nombre))
    {
        string mssg = "Excedeed maximum size nombre: " +
                      sizeof(cliente.nombre);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (direccion.length() > sizeof(cliente.direccion))
    {
        string mssg = "Excedeed maximum size direccion: " +
                      sizeof(cliente.direccion);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (telefono.length() > sizeof(cliente.telefono))
    {
        string mssg = "Excedeed maximum size telefono: " +
                      sizeof(cliente.telefono);
        cout << mssg << endl;
        TypeError::New(env, mssg).ThrowAsJavaScriptException();
        return env.Null();
    }
    strcpy(cliente.nombre, nombre.c_str());
    strcpy(cliente.direccion, direccion.c_str());
    strcpy(cliente.telefono, telefono.c_str());

    cout << "Cliente id: " << cliente.id << endl;
    cout << "Cliente nombre: " << cliente.nombre << endl;
    cout << "Cliente direccion: " << cliente.direccion << endl;
    cout << "Cliente telefono: " << cliente.telefono << endl;

    Controller<Cliente> controller((char *)"Cliente.dat");
    if (!controller.Insert(cliente))
    {
        return String::New(env, "Failed");
    }
    return String::New(env, "Successfully inserted");
}

Object Init(Env env, Object exports)
{
    exports.Set(String::New(env, "InsertProducto"), Function::New<InsertProducto>(env));
    exports.Set(String::New(env, "InsertProveedor"), Function::New<InsertProveedor>(env));
    exports.Set(String::New(env, "InsertCompra"), Function::New<InsertCompra>(env));
    exports.Set(String::New(env, "InsertFactura"), Function::New<InsertFactura>(env));
    exports.Set(String::New(env, "InsertCliente"), Function::New<InsertCliente>(env));

    return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);