const path = require('path');
const { app, BrowserWindow } = require('electron');

const TDS = require('./modules/index');

function createMainWindow(){
    const mainWindow = new BrowserWindow({
        title: 'Transactional System',
        width: 500,
        height: 600
    });
    mainWindow.loadFile(path.join(__dirname, './app/renderer/index.html'));
}

app.whenReady().then(() => {
    createMainWindow(); 
});