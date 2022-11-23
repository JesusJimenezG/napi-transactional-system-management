const debug = require('debug');
var TDS = require('../build/Debug/TDS.node');

const producto = {
    "id": "1",
    "id_proveedor": "1",
    "stock": "5",
    "precio": "50.0",
    "descripcion": "Un producto",
    "stock_min": "500"
}

// console.log(TDS);
// debug(TDS.InsertProducto(producto));
console.log(TDS.InsertProducto(producto));

module.exports = TDS;