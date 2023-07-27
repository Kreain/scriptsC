import fs from 'fs'
import fetch from 'node-fetch'

const cookie = {
    name: 'MoodleSession',
    value: 'fcijougg3mhctcld721f3utlsk'
}

let maxSearchNumber = 2091

const getName = async (id) => {
    return new Promise((resolve, reject) => {
        fetch(`https://gandalf.epitech.eu/user/profile.php?id=${id}`, {
            method: 'GET',
            headers: {
                'Cookie': `${cookie.name}=${cookie.value}; block-fcl_a0df30936b379fee69867f77207a3407=collapsed; block-fcl_94de1a4f35bea7d675bd0e69fde883a1=collapsed`
            }
        }).then(response => {
            if (response?.status === 200)
                response.text().then(doc => resolve(doc.split("<title>")[1].split("</title>")[0]?.split(": Public")[0]))
            else
                reject(`##Status was: ${response?.status}##`)
        }).catch(console.error)
    })
}

const generateNames = async () => {
    const names = []

    let id = 0
    console.log("Generating Names")
    while (id++ < maxSearchNumber) {
        let name
        try {
            name = await getName(id)
            name = name.length === 0 ? "!!NO NAME!!" : name
        } catch (err) {
            name = err.cause
        }
        names.push({ id: id, name: name })
    }
    fs.writeFile('./names.json', JSON.stringify(names), (err) => {
        if (err)
            console.error(err)
        console.log("File saved!!")
    })
}

const findUser = (id = null, name = null) => {
    fs.readFile('./names.json', 'utf8', (err, data) => {
        if (err) {
            console.error(err)
            return
        }
        if (data.length <= 0) {
            console.log("No names in the file")
            return
        }
        let jsonData = JSON.parse(data)

        let users = jsonData.filter(user => id !== null ? user.id == id : user.name.toLowerCase().includes(name.toLowerCase()))
        users.forEach(user => console.log(`[${user?.id}]: ${user?.name}`))
    })
}

const main = () => {
    const args = process.argv.slice(2)

    if (args.length > 0) {
        if (args.includes("-g")) {
            generateNames()
            return
        }
        if (args.includes("-f")) {
            const index = args.indexOf("-f")
            if (index + 1 === args.length)
                return
            const search = args[index + 1].split("=")
            switch(search[0].toLowerCase()) {
                case 'name': findUser(null, search[1]); break
                case 'id': findUser(search[1], null); break
                default: return
            }
        }
    }
}

main()