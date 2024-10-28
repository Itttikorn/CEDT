// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/11.0.1/firebase-app.js";
import { getDatabase, ref, onChildAdded, onChildChanged, set, get } from "https://www.gstatic.com/firebasejs/11.0.1/firebase-database.js";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
    //your firebase config
};

const app = initializeApp(firebaseConfig);
const database = getDatabase(app);
// Function to toggle the state and update Firebase

function toggleOn() {
    var config = {
        state: true
    };

    var dbRef = ref(database, "state");
    set(dbRef, true)
        .then(function () {
            console.log("Success!");
        })
        .catch(function (error) {
            console.log("Error: " + error.message);
        });
}

function toggleOff() {
    var config = {
        state: false,
    };

    var dbRef = ref(database, "state");
    set(dbRef, false)
        .then(function () {
            console.log("Success!");
        })
        .catch(function (error) {
            console.log("Error: " + error.message);
        });
    }
function setupDatabaseListeners() {
    var dbRef = ref(database, "state/");
    // Get a database reference to all config/ keys.
    onChildAdded(dbRef, configChanged, dbErrorCallback);
    onChildChanged(dbRef, configChanged, dbErrorCallback);
    // Callback invoked when database entry is added or changed.
    function configChanged(snapshot) {
        // var key = snapshot.key;
        var newValue = snapshot.val();
        document.getElementById("state").innerText = "lights on: " + newValue;
    }
    // Callback invoked on error.
    function dbErrorCallback(err) {
        console.log("Error reading database: " + err.message);
    }
}

setupDatabaseListeners();
document.getElementById("getstate").addEventListener("click", function () {
    var dbRef = ref(database, "state");
    get(dbRef).then((snapshot) => {
        if (snapshot.exists()) {
            document.getElementById("state").innerText = "lights on: " + snapshot.val();
        } else {
            console.log("No data available");
        }
    }).catch((error) => {
        console.error("Error getting state: ", error);
    });
});
document.getElementById("on").addEventListener("click", toggleOn);
document.getElementById("off").addEventListener("click", toggleOff);