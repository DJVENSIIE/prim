// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// No Node.js APIs are available in this process because
// `nodeIntegration` is turned off. Use `preload.js` to
// selectively enable features needed in the rendering
// process.

const {MachineStuff} = require("../../model/machine");
const {TrKeys,Translation} = require("../../utils/translation");
let machines = document.getElementById("machines-list");

// all machines
for (const machine of config.machines) {

    let pathToFile;
    switch (machine.type) {
        case MachineStuff.MS_COLLECTOR:
        case MachineStuff.MS_CONVEYOR_BELT:
        case MachineStuff.MS_RECYCLING_CENTER:
            pathToFile = machine.pathToFile+'BOT.png';
            break;
        case MachineStuff.MS_CROSS_BELT:
            pathToFile = machine.pathToFile+'BOT_LEFT.png';
            break;
        case MachineStuff.MS_JUNKYARD:
            pathToFile = machine.pathToFile;
            break;
    }

    let div = document.createElement("div");
    div.classList.add("border", "border-dark" ,"mt-3", "p-3")
    let price=Translation.get(TrKeys.MACHINE_PRICE);
    let price_destroy=Translation.get(TrKeys.MACHINE_PRICE_DESTROY);
    let orientation=Translation.get(TrKeys.MACHINE_ORIENTATION);
    let and_word =Translation.get(TrKeys.AND_WORD);
    // upgrade message
    let up = "", capacity,capacity2,up2="";
    if (machine.canUpgrade) {
        up2 = Translation.get((TrKeys.MACHINE_PRICE_UPDATE));
        up =`${up2} <span class="text-success">${machine.costUpgradeE}</span> E ${and_word} 
        <span class="text-success">${machine.costUpgradeDD}</span> DD <br>`;
    }

    // unlimited capacity
    if (machine.capacity === Number.MAX_VALUE) capacity = '';
    else
    {
        capacity2 = Translation.get(TrKeys.MACHINE_CAPACITY);
        capacity = `${capacity2} <span class="text-success">${machine.capacity}</span><br>`;
    }
    div.innerHTML = `<div class="">
                <span class="fw-bold">${machine.name}</span>
                <i class="text-success">id=${machine.type}, <img src="${pathToFile}"></i>
            </div>
            <p>${machine.description}</p>
            <span>
                ${price}
                <span class="text-success">${machine.costE}</span> E ${and_word} 
                <span class="text-success">${machine.costDD}</span> DD <br>
                ${up}
                ${price_destroy}
                <span class="text-success">${machine.costDestroyE}</span> E ${and_word}  
                <span class="text-success">${machine.costDestroyDD}</span> DD <br>
                ${orientation} <span class="text-success">${machine.defaultOrientation}</span> <br>
                ${capacity}
            </span>`
    machines.append(div)
}