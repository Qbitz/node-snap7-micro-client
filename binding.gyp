{
    "targets": [
        {
            "target_name": "node_snap7_micro_client",
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "./src"
            ],
            "sources": [
                "./src/node_snap7.cpp",
                "./src/node_snap7_client.cpp",
                "./src/snap7.cpp"
            ],
            "conditions": [],
            "dependencies": [
                "snap7-micro-client"
            ]
        },
        {
            "target_name": "snap7-micro-client",
            "type": "static_library",
            "include_dirs": [
                "./deps/snap7-micro-client-lib/src/core/",
                "./deps/snap7-micro-client-lib/src/lib/",
                "./deps/snap7/src/core",
                "./deps/snap7/src/sys"
            ],
            "sources": [
                "./deps/snap7/src/sys/snap_msgsock.cpp",
                "./deps/snap7/src/sys/snap_sysutils.cpp",
                "./deps/snap7/src/core/s7_isotcp.cpp",
                "./deps/snap7/src/core/s7_peer.cpp",
                "./deps/snap7/src/core/s7_micro_client.cpp",
                "./deps/snap7-micro-client-lib/src/core/s7_text.cpp",
                "./deps/snap7-micro-client-lib/src/core/s7_client-wrapper.cpp",
                "./deps/snap7-micro-client-lib/src/lib/snap7_libmain.cpp"
            ],
            "conditions": [
                ["OS=='android' or OS=='linux' or OS=='freebsd'", {
                    "cflags_cc": ["-fPIC", "-fexceptions"],
                    "cflags_cc!": ["-fno-exceptions"]
                }],
                ["OS=='mac' or OS=='ios'", {

                    "xcode_settings": {
                        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                        "GCC_DYNAMIC_NO_PIC": "NO",
                        "OTHER_CFLAGS": ["-pedantic"]
                    }
                }]
            ]
        }
    ]
}
