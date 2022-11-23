{
    "targets": [{
        "target_name": "TDS",
        "cflags!": ["-fno-exceptions"],
        "cflags_cc!": ["-fno-exceptions"],
        "sources": [
            "modules/src/main.cpp"
        ],
        "include_dirs": [
            # "node_modules/node-addon-api",
            "<!(node -e \"require('nan')\")",
            "<!(node -p \"require('node-addon-api').include_dir\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS']
    }]
}
